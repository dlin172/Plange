#include <cassert>
#include <stack>
#include <deque>

#include "parlex/details/subjob.hpp"
#include "parlex/parser.hpp"
#include "parlex/details/job.hpp"
#include "parlex/details/context.hpp"
#include "parlex/permutation.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/producer.hpp"
#include "logging.hpp"
#include "perf_timer.hpp"

//#define FORCE_RECURSION

namespace parlex {

parser::parser(int threadCount) : activeCount(0), terminating(false) {
	for (; threadCount > 0; --threadCount) {
		workers.emplace_back([=]() {
			//DBG("thread ", threadCount, " started");
			std::unique_lock<std::mutex> lock(mutex);
			goto wait;
			while (!terminating) {
				{
					//DBG("THREAD ", threadCount, " POPPING ITEM");
					std::tuple<details::context_ref, int> item = work.front();
					work.pop();
					lock.unlock();
					auto const & context = std::get<0>(item);
					auto const nextDfaState = std::get<1>(item);
					//DBG("thread ", threadCount, " executing dfa state");
					context.owner().machine.process(context, nextDfaState);
					context.owner().end_dependency(); //reference code A
					if (--activeCount == 0) {
						halt_cv.notify_one();
					}
					lock.lock();
				}
wait:
				work_cv.wait(lock, [this]() { return work.size() > 0 || terminating; });
			}
		});
	}
}

parser::~parser() {
	terminating = true;
	work_cv.notify_all();
	for (auto & thread : workers) {
		thread.join();
	}
}

abstract_syntax_graph parser::parse(grammar const & g, recognizer const & r, std::u32string const & document) {
	perf_timer timer("parse");
	std::unique_lock<std::mutex> lock(mutex); //use the lock to make sure we see activeCount != 0
	details::job j(*this, document, g, r);
#ifndef FORCE_RECURSION
	assert(activeCount > 0);
#endif
	while (true) {
		halt_cv.wait(lock, [this](){ return activeCount == 0; });
		//DBG("parser is idle; checking for deadlocks");
		if (handle_deadlocks(j)) {
			break;
		}
	};
	assert(activeCount == 0);
	return construct_result(j, match(match_class(r, 0), document.size()));
}

abstract_syntax_graph parser::parse(grammar const & g, std::u32string const & document) {
	return parse(g, g.get_main_production(), document);
}

void parser::schedule(details::context_ref const & c, int nextDfaState) {
	//DBG("scheduling m: ", c.owner().machine.get_id(), " b:", c.owner().documentPosition, " s:", nextDfaState, " p:", c.current_document_position());
#ifndef FORCE_RECURSION
	activeCount++;
	std::unique_lock<std::mutex> lock(mutex);
	work.emplace(std::make_tuple(c, nextDfaState));
	work_cv.notify_one();
#else
	c.owner().machine.process(c, nextDfaState);
#endif
}

bool matches_intersect(parlex::match const & left, parlex::match const & right) {
	return
		left.document_position < (right.document_position + right.consumed_character_count) &&
		(left.document_position + left.consumed_character_count) > right.document_position;
}

std::set<match> getChildren(abstract_syntax_graph const & asg, match const & m) {
	std::set<match> result;
	auto i = asg.table.find(m);
	if (i == asg.table.end()) {
		return std::set<match>();
	}
	for (permutation const & perm : i->second) {
		for (match const & m : perm) {
			result.insert(m);
		}
	}
	return result;
}

struct node_props_t {
	match const & m;
	recognizer const & r;
	std::set<permutation> & permutations;
	std::set<match> children;
	std::map<match, std::set<permutation>> parentPermutationsByMatch;
	size_t height;
	std::set<match> allDescendents;
	std::set<match> allAncestors;
	std::set<match> allDescendentsAndAncestors;
	std::set<match> allIntersections;
	bool pruned;

	inline node_props_t(abstract_syntax_graph & asg, match const & m) : m(m), r(m.r), permutations(asg.table[m]), children(getChildren(asg, m)), height(0), pruned(false) {}
};

void prune(abstract_syntax_graph & asg, std::map<match, node_props_t> & nodes, node_props_t & props) {
	std::queue<match> toPrune;
	std::set<match> completed;
	std::function<void(match const &)> add = [&] (match const & m) {
		if (completed.insert(m).second) {
			toPrune.push(m);
		}
	};
	add(props.m);
	while (!toPrune.empty()) {
		match thisMatch = toPrune.front();
		node_props_t & props = nodes.find(thisMatch)->second;
		toPrune.pop();
		for (auto const & parentMatchAndPermutations : props.parentPermutationsByMatch) {
			match const & parentMatch = parentMatchAndPermutations.first;
			node_props_t & parentProps = nodes.find(parentMatch)->second;
			std::set<permutation> const & parentPermutations = parentMatchAndPermutations.second;
			for (permutation const & perm : parentPermutations) {
				parentProps.permutations.erase(perm);
				if (parentProps.permutations.size() == 0) {
					add(parentMatch);
				}
			}
		}
		for (match const & descendentMatch : props.allDescendents) {
			node_props_t & descendent = nodes.find(descendentMatch)->second;
			descendent.allAncestors.erase(thisMatch);
			if (descendent.allAncestors.empty()) {
				add(descendentMatch);
			}
			descendent.allDescendentsAndAncestors.erase(thisMatch);
			descendent.parentPermutationsByMatch.erase(thisMatch);
		}
		for (match const & ancestorMatch : props.allAncestors) {
			node_props_t & ancestor = nodes.find(ancestorMatch)->second;
			ancestor.allDescendents.erase(thisMatch);
			ancestor.allDescendentsAndAncestors.erase(thisMatch);
			ancestor.children.erase(thisMatch);
		}
		for (match const & intersectorMatch : props.allIntersections) {
			node_props_t & intersector = nodes.find(intersectorMatch)->second;
			intersector.allIntersections.erase(thisMatch);
		}
	}
	for (match const & i : completed) {
		asg.table.erase(i);
		nodes.erase(i);
	}
}

void construct_nodes(abstract_syntax_graph & asg, std::map<match, node_props_t> & nodes, std::vector<std::set<node_props_t *>> & flattened) {
	std::queue<node_props_t *> propertyConstructQueue;
	std::set<node_props_t *> constructedProps;
	for (auto const & entry : asg.table) {
		match const & m = entry.first;
		node_props_t & nodeProps = nodes.emplace(std::piecewise_construct, std::forward_as_tuple(m), std::forward_as_tuple(asg, m)).first->second;
		constructedProps.insert(&nodeProps);
		propertyConstructQueue.push(&nodeProps);
	}
	while (!propertyConstructQueue.empty()) {
		node_props_t & props = *propertyConstructQueue.front();
		propertyConstructQueue.pop();
		if (props.permutations.empty()) {
			props.height = 0;
		}

		for (std::set<permutation>::iterator i = props.permutations.begin(); i != props.permutations.end(); ++i) {
			permutation const & perm = *i;
			for (match const & child : perm) {
				node_props_t & childProps = nodes.emplace(std::piecewise_construct, std::forward_as_tuple(child), std::forward_as_tuple(asg, child)).first->second;
				childProps.parentPermutationsByMatch[props.m].insert(perm);
				if (constructedProps.insert(&childProps).second) {
					propertyConstructQueue.push(&childProps);
				};
			}
		}

		size_t const afterIndex = props.m.document_position + props.m.consumed_character_count;
		for (size_t i = props.m.document_position; i < afterIndex; ++i) {
			flattened[i].insert(&props);
		}
	}
}

void resolve_nodes(std::map<match, node_props_t> & nodes) {
	//work queue for the algorithm
	std::queue<std::tuple<node_props_t *, node_props_t *, int>> propertyResolveQueue;

	for (auto & entry : nodes) {
		node_props_t & props = entry.second;
		//seed algorithm with "match A has all of match A's permutation's matches as descendants"
		propertyResolveQueue.push(std::make_tuple(&props, &props, 0));
	}

	//containment algorithm
	//match A contains all of match B's permutation's matches
	while (!propertyResolveQueue.empty()) {
		std::tuple<node_props_t *, node_props_t *, int> entry = propertyResolveQueue.front();
		propertyResolveQueue.pop();
		node_props_t & left = *std::get<0>(entry);
		node_props_t & right = *std::get<1>(entry);
		size_t const leftsHeightMinusRightsHeight = std::get<2>(entry);
		if (right.height == 0) { //if right is a leaf
			left.height = std::max(leftsHeightMinusRightsHeight, left.height);
		}
		for (permutation const & perm : right.permutations) {
			for (match const & containedMatch : perm) {
				node_props_t & childProps = nodes.find(containedMatch)->second;
				if (left.allDescendents.insert(childProps.m).second) {
					propertyResolveQueue.push(std::make_tuple(&left, &nodes.find(containedMatch)->second, leftsHeightMinusRightsHeight + 1));
				}
				childProps.allAncestors.insert(left.m);
				childProps.allDescendentsAndAncestors.insert(left.m);
				left.allDescendentsAndAncestors.insert(childProps.m);
			}
		}
	}
}

void compute_intersections(std::vector<std::set<node_props_t *>> const & flattened) {
	for (size_t i = 0; i < flattened.size(); ++i) {
		for (std::set<node_props_t *>::iterator j = flattened[i].begin(); j != flattened[i].end(); ++j) {
			node_props_t & left = **j;
			std::set<node_props_t *>::iterator k = j;
			++k;
			for (; k != flattened[i].end(); ++k) {
				node_props_t & right = **k;
				if (&left == &right) {
					continue;
				}
				if (left.allDescendentsAndAncestors.count(right.m) == 0) {
					left.allIntersections.insert(right.m);
					right.allIntersections.insert(left.m);
				}
			}
		}
	}
}

std::vector<std::set<match>> ordered_matches_by_height(std::map<match, node_props_t> & nodes) {
	std::vector<std::set<match>> orderedMatchesByHeight;
	for (auto & entry : nodes) {
		node_props_t & node = entry.second;
		if (orderedMatchesByHeight.size() <= node.height) {
			orderedMatchesByHeight.resize(node.height + 1);
		}
		orderedMatchesByHeight[node.height].insert(node.m);
	}
	return orderedMatchesByHeight;
}

void apply_test(abstract_syntax_graph & asg, grammar const & g, std::map<match, node_props_t> & nodes, std::vector<std::set<match>> orderedMatchesByHeight, std::function<bool(grammar const &, node_props_t &, node_props_t &)> test) {
	for (size_t height = 0; height < orderedMatchesByHeight.size(); ++height) {
		std::set<match> const & matches = orderedMatchesByHeight[height];
		for (auto & aMatch : matches) {
			auto i = nodes.find(aMatch);
			if (i == nodes.end()) { //check if it has been deleted since we generated orderedMatchesByHeight
				continue;
			}
			node_props_t & aProps = i->second;
			if (aProps.m.r.is_terminal()) {
				continue;
			}
			state_machine & aStateMachine = *(state_machine *)&aProps.m.r;
			for (match const & bMatch : aProps.allIntersections) {
				auto j = nodes.find(bMatch);
				if (j == nodes.end()) { //check if it has been deleted since we generated orderedMatchesByHeight
					continue;
				}
				node_props_t & bProps = j->second;
				if (bProps.m.r.is_terminal()) {
					continue;
				}
				state_machine & bStateMachine = *(state_machine *)&bProps.m.r;
				if (test(g, aProps, bProps)) {
					prune(asg, nodes, aProps);
					break;
				}
			}
		}
	}
}

bool precedence_test(grammar const & g, node_props_t & a, node_props_t & b)
{
	if (&a.m.r == &b.m.r) {
		return false;
	}
	return g.test_precedence(*(state_machine*)&b.m.r, *(state_machine*)&a.m.r);
}

bool associativity_test(grammar const & g, node_props_t & a, node_props_t & b) {
	if (&a != &b) {
		return false;
	}
	associativity const assoc = ((state_machine*)&a.m.r)->get_associativity();
	switch (assoc) {
	case associativity::left:
	case associativity::any:
		return a.m.document_position > b.m.document_position;
	case associativity::right:
		return a.m.document_position < b.m.document_position;
	case associativity::none:
		return false;
	}
	throw std::exception("Invalid associativity value");
}

abstract_syntax_graph & apply_precedence_and_associativity(grammar const & g, abstract_syntax_graph & asg) {

	std::map<match, node_props_t> nodes;
	//a per-character table of matches
	std::vector<std::set<node_props_t *>> flattened;
	flattened.resize(asg.root.consumed_character_count);

	construct_nodes(asg, nodes, flattened);
	resolve_nodes(nodes);
	compute_intersections(flattened);
	std::vector<std::set<match>> orderedMatchesByHeight = ordered_matches_by_height(nodes);
	apply_test(asg, g, nodes, orderedMatchesByHeight, precedence_test);
	apply_test(asg, g, nodes, orderedMatchesByHeight, associativity_test);

	return asg;
}

abstract_syntax_graph parser::construct_result(details::job const & j, match const & match) {
	perf_timer timer("construct_result");
	abstract_syntax_graph step1(match);
	for (auto const & pair : j.producers) {
		details::producer const & producer = *pair.second;
		for (auto const & pair2 : producer.match_to_permutations) {
			struct match const & match = pair2.first;
			std::set<permutation> const & permutations = pair2.second;
			step1.table[match] = permutations;
		}
	}
	std::string check = step1.to_dot();
	abstract_syntax_graph step2 = step1.is_rooted() ? apply_precedence_and_associativity(j.g, step1) : step1;
	std::string check2 = step2.to_dot();
	return step2;
}

bool parser::handle_deadlocks(details::job const & j) {
	assert(activeCount == 0);
	perf_timer timer("handle_deadlocks");

	//build a dependency graph and detect cyclical portions that should be halted
	//if no subjobs remain, return true
	//otherwise return false (still work to be done)

	std::stack<std::pair<match_class, match_class>> s;

	//Examine subscriptions from one subjob to another to construct the graph
	std::map<match_class, std::set<match_class>> direct_subscriptions;
	std::map<match_class, std::set<match_class>> all_subscriptions;
	for (auto const & i : j.producers) {
		match_class const & matchClass = i.first;
		details::producer const & p = *i.second;
		if (p.r.is_terminal() || p.completed) {
			continue;
		}
		for (auto const & subscription : p.consumers) {
			details::context_ref const & c = subscription.c;
			match_class temp(c.owner().machine, c.owner().documentPosition);
			all_subscriptions[matchClass].insert(temp);
			direct_subscriptions[matchClass].insert(temp);
			s.push(std::pair<match_class, match_class>(matchClass, temp));
		}
	}

	//Apply transitivity to the graph
	while (s.size() > 0) {
		std::pair<match_class, match_class> entry = s.top();
		s.pop();
		for (auto const & next : direct_subscriptions[entry.first]) {
			if (all_subscriptions[entry.first].insert(next).second) {
				s.push(std::pair<match_class, match_class>(entry.first, next));
			};
		}
	}

    bool anyHalted = false;
	//halt subjobs that are subscribed to themselves (in)directly
	for (auto const & i : all_subscriptions) {
		match_class const & matchClass = i.first;
		details::producer &p = *j.producers.find(matchClass)->second;
		if (i.second.count(matchClass) > 0) {
			p.terminate();
			anyHalted = true;
		}
	}
	return !anyHalted;
}

}
