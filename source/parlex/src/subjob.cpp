#include "parlex/details/subjob.hpp"

#include "parlex/details/parser.hpp"
#include "parlex/details/recognizer.hpp"
#include "parlex/details/state_machine_base.hpp"

#include "parlex/details/context.hpp"
#include "parlex/details/job.hpp"

#include "utils.hpp"

namespace parlex {
namespace details {

subjob::subjob(
	job & owner,
	state_machine_base const & machine,
	int documentPosition
):
	producer(owner, machine, documentPosition),
	machine(machine),
	lifetimeCounter(1) //see finish_creation
{
	//DBG("constructed subjob b:", documentPosition, " m:", machine);
}

subjob::~subjob() {
	//DBG("destructing subjob b:", documentPosition, " m:", machine);
}

void subjob::start() { {
		std::unique_lock<std::mutex> lock(mutex);
		contexts.emplace_front(*this, nullptr, document_position, std::optional<match>(), nullptr);
	}
	machine.start(*this, document_position);
	end_dependency(); //reference code B
}

// context const & subjob::construct_start_state_context(int documentPosition) {
// 	std::unique_lock<std::mutex> lock(mutex);
// 	auto i = contexts.emplace_front(*this, nullptr, documentPosition, std::optional<match>());
// 	return *i;
// }

context const & subjob::construct_stepped_context(context const* const prior, match const & fromTransition, behavior::leaf const * leaf) {
	std::unique_lock<std::mutex> lock(mutex);
	auto i = contexts.emplace_front(*this, prior, prior->currentDocumentPosition + fromTransition.consumed_character_count, std::optional<match>(fromTransition), leaf);
	return *i;
}

void subjob::on(context const & c, recognizer const & r, int nextDfaState, behavior::leaf const * leaf) {
	if (c.currentDocumentPosition >= c.owner.owner.document.length()) {
		return;
	}
	increment_lifetime(); //reference code C
	owner.connect(match_class(r, c.currentDocumentPosition), c, nextDfaState, leaf);
}

void subjob::accept(context const & c) {
	int len = c.currentDocumentPosition - c.owner.document_position;
	if (len == 0) {
		return;
	}
	throw_assert(&c.owner == this);
	permutation p = c.result();
	if (!machine.get_filter()) {
		//DBG("Accepting r:", r.id, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		enque_permutation(len, p);
	} else {
		//DBG("Candidate r:", r.id, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		std::unique_lock<std::mutex> lock(mutex);
		queuedPermutations.push_back(p);
	}
}

void subjob::decrement_lifetime() {
	int temp = --lifetimeCounter;
	//DBG("decrement_lifetime m:", machine, " b:", documentPosition, " r:", temp);
	if (temp > 0) {
		return;
	}
	flush();
	terminate();
}

void subjob::end_dependency() {
	//DBG("end_dependency m:", machine, " b:", documentPosition);
	decrement_lifetime();
}

void subjob::finish_creation() {
	//DBG("finish_creation m:", machine, " b:", documentPosition);
	decrement_lifetime();
}

void subjob::increment_lifetime() {
	int temp = ++lifetimeCounter;
	throw_assert(temp > 1);
	//DBG("increment_lifetime m:", machine, " b:", documentPosition, " r:", temp);
}

void subjob::flush() {
	///DBG("flush m:", machine, " b:", documentPosition);
	filter_function const & filter = machine.get_filter();
	if (filter != nullptr) {
		std::unique_lock<std::mutex> lock(mutex);
		if (queuedPermutations.size() == 0) {
			return;
		}
		std::set<int> selections = (*filter)(owner.document, queuedPermutations);
		int counter = 0;
		for (auto const & permutation : queuedPermutations) {
			if (selections.count(counter) > 0) {
				int len = permutation.size() > 0 ? permutation.back().document_position + permutation.back().consumed_character_count - document_position : 0;
				enque_permutation(len, permutation);
			}
			counter++;
		}
	}
}

} // namespace details
} // namespace parlex
