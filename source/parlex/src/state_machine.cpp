#include "parlex/detail/state_machine.hpp"

#include "parlex/associativity.hpp"
#include "parlex/builder.hpp"
#include "parlex/detail/job.hpp"
#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

state_machine::state_machine(std::string const & name, filter_function const & filter, associativity const assoc) : recognizer(name), filter(filter), assoc(assoc), behavior(nullptr), start_state(-1), accept_state_count(-1) {
}

void state_machine::set_behavior(node & behavior) {
	this->behavior = &behavior;
	auto dfa = reorder(behavior.compile());
	auto transitions = dfa.get_transitions();
	for (auto const & t : transitions) {
		while (states.size() <= t.to || states.size() <= t.from) {
			states.emplace_back();
		}
		transition_info_t transitionInfo{};
		transitionInfo.l = t.symbol;
		transitionInfo.recognizer_index = t.symbol->recognizer_index;
		states[t.from][transitionInfo] = uint8_t(t.to);
	}
	start_state = uint8_t(*dfa.start_states.begin());
	accept_state_count = uint8_t(dfa.accept_states.size());
}

void state_machine::process(job & j, subjob & mySubjob, match_class const & mySubjobId, context const & c, uint8_t const dfaState) const {
	//DBG("processing '", get_id(), "' dfaState:", dfaState, " p:", c.current_document_position());
	if (dfaState >= states.size() - accept_state_count) {
		accept(j, mySubjob, mySubjobId, c);
	}
	for (auto const & kvp : states[dfaState]) {
		auto const & transitionInfo = kvp.first;
		int const nextState = kvp.second;
		//DBG("'", get_id(), "' state ", dfaState, " position ", c.current_document_position(), " subscribes to '", transition.name, "' position ", c.current_document_position());
		on(j, mySubjob, mySubjobId, transitionInfo.recognizer_index, c, nextState, transitionInfo.l);
	}
}

void state_machine::start(job & j, subjob & mySubjob, match_class const & mySubjobId, context const & c) const {
	process(j, mySubjob, mySubjobId, c, get_start_state());
}

void state_machine::on(job & j, subjob & mySubjob, match_class const & mySubjobId, uint16_t const requestedRecognizerIndex, context const & c, uint8_t const nextDfaState, leaf const * leaf) {
	mySubjob.on(j, mySubjobId, requestedRecognizerIndex, c, nextDfaState, leaf);
}

void state_machine::accept(job & j, subjob & mySubjob, match_class const & mySubjobId, context const & c) {
	mySubjob.accept(j, mySubjobId, c);
}

automaton state_machine::reorder(automaton const & dfa) {
	//construct a map from dfa states to reordered states
	std::map<size_t, size_t> stateMap;
	auto const startState = *dfa.start_states.begin();
	auto const startIsAccept = dfa.accept_states.count(startState) > 0;
	if (!startIsAccept) {
		stateMap[*dfa.start_states.begin()] = 0;
	}
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		//all the un-added non-accept states
		if (i != startState && dfa.accept_states.count(i) == 0) {
			stateMap[i] = stateMap.size();
		}
	}
	if (startIsAccept) {
		stateMap[*dfa.start_states.begin()] = stateMap.size();
	}
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		//all the unadded accept states
		if (i != startState && dfa.accept_states.count(i) > 0) {
			stateMap[i] = stateMap.size();
		}
	}

	//it's a bimap, construct reverse lookup
	std::map<size_t, size_t> stateMapDual;
	for (auto const & i : stateMap) {
		stateMapDual[i.second] = i.first;
	}

	//construct the reordered dfa
	automaton reordered;
	auto const firstAcceptState = dfa.states.size() - dfa.accept_states.size();
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		auto const dual = stateMapDual[i];
		auto const & dfaState = dfa.states[dual];
		reordered.add_state(i, i >= firstAcceptState, dual == startState);
		auto & reorderedState = reordered.states[i];
		for (auto outTransition : dfaState.out_transitions) {
			reorderedState.out_transitions[outTransition.first] = { stateMap[*outTransition.second.begin()] };
		}
	}
	return reordered;
}

bool state_machine::is_terminal() const {
	return false;
}

uint8_t state_machine::get_start_state() const {
	return start_state;
}

filter_function state_machine::get_filter() const {
	return filter;
}

associativity state_machine::get_assoc() const {
	return assoc;
}

std::string state_machine::to_dot(std::vector<recognizer const *> const & recognizers) const {
	std::vector<uint8_t> stateInts;
	for (uint8_t i = 0; i < states.size(); ++i) {
		stateInts.push_back(i);
	}

	auto const getName = [&](uint8_t const & i) { return std::to_string(i); };

	auto const getEdges = [&](uint8_t const & i) {
		std::vector<std::pair<std::string, uint8_t>> edges;
		for (auto const & edge : states[i]) {
			auto transitionInfo = edge.first;
			auto toState = edge.second;
			auto const & recognizer = *recognizers[transitionInfo.recognizer_index];
			std::stringstream ss;
			ss << transitionInfo.l;
			edges.emplace_back("label=" + enquote(recognizer.name + " (" + ss.str() + ")"), toState);
		}
		return edges;
	};

	auto const getProperties = [&](uint8_t const & i) {
		std::string nodeProperties;
		if (i == start_state) {
			nodeProperties = "color=red";
		}
		if (i >= states.size() - accept_state_count) {
			if (!nodeProperties.empty()) {
				nodeProperties += ", ";
			}
			nodeProperties += "shape=doublecircle";
		}
		return nodeProperties;
	};

	return directed_graph<uint8_t>(stateInts, getName, getEdges, getProperties);

}

collections::coherent_map<state_machine::transition_info_t, uint8_t> const & state_machine::get_transitions(size_t stateIndex) const
{
	return states[stateIndex];
}

} // namespace detail
} // namespace parlex
