#include "parlex/detail/subjob.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/job.hpp"
#include "parlex/detail/match_class.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/state_machine.hpp"

#include "utils.hpp"
// ReSharper disable once CppUnusedIncludeDirective
#include "logging.hpp"

namespace parlex {
namespace detail {

subjob::subjob(state_machine const & machine) :
	machine(machine),
	lifetime_counter(1) //see finish_creation
{
	//DBG("constructed subjob p:", documentPosition, " m:", machine);
}

subjob::~subjob() {
	//DBG("destructing subjob p:", document_position, " m:", machine);
}

void subjob::start(job & j, match_class const & myId) {
	machine.start(j, *this, myId, construct_start_state_context(myId.document_position));
	finish_creation(j, myId);
}

context const & subjob::construct_start_state_context(uint32_t const documentPosition) {
	auto const i = contexts.emplace_front(nullptr, documentPosition, std::optional<match>(), nullptr);
	return *i;
}

context const & subjob::construct_stepped_context(context const* const prior, match const & fromTransition, leaf const * l) {
	auto const i = contexts.emplace_front(prior, prior->current_document_position + fromTransition.consumed_character_count, std::optional<match>(fromTransition), l);
	return *i;
}

void subjob::on(job & j, match_class const & myId, uint16_t const recognizerIndex, context const & c, uint8_t const nextDfaState, leaf const * l) {
	if (c.current_document_position >= j.document.length()) {
		return;
	}
	begin_subscription_reference();
	j.connect(match_class(c.current_document_position, recognizerIndex), *this, myId, c, nextDfaState, l);
}

void subjob::accept(job & j, match_class const & myInfo, context const & c) {
	int const len = c.current_document_position - myInfo.document_position;
	if (len == 0) {
		return;
	}
	auto const p = c.result();
	if (!machine.get_filter()) {
		//DBG("Accepting r:", r.name, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		enque_permutation(j, myInfo, len, p);
	} else {
		//DBG("Candidate r:", r.name, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		std::unique_lock<std::mutex> lock(mutex);
		queued_permutations.push_back(p);
	}
}

void subjob::increment_lifetime() {
	auto const temp = ++lifetime_counter;
	throw_assert(temp > 1);
	//DBG("increment_lifetime m:", machine, " b:", documentPosition, " r:", temp);
}

void subjob::decrement_lifetime(job & j, match_class const & myId) {
	auto const temp = --lifetime_counter;
	//DBG("decrement_lifetime m:", machine, " b:", documentPosition, " r:", temp);
	if (temp > 0) {
		return;
	}
	flush(j, myId);
	contexts.clear();
	queued_permutations.clear();
	terminate(j, myId);
}

void subjob::finish_creation(job & j, match_class const & myId) {
	//corresponds with the constructor's setting of lifetimeCounter to 1
	//DBG("finish_creation m:", machine, " b:", documentPosition);
	decrement_lifetime(j, myId);
}

void subjob::begin_work_queue_reference() {
	increment_lifetime();
}

void subjob::end_work_queue_reference(job & j, match_class const & myId) {
	decrement_lifetime(j, myId);
}

void subjob::begin_subscription_reference() {
	increment_lifetime();
}

void subjob::end_subscription_reference(job & j, match_class const & myId) {
	decrement_lifetime(j, myId);
}

void subjob::flush(job & j, match_class const & myInfo) {
	///DBG("flush m:", machine, " b:", documentPosition);
	auto const & filter = machine.get_filter();
	if (filter != nullptr) {
		std::unique_lock<std::mutex> lock(mutex);
		if (queued_permutations.empty()) {
			return;
		}
		auto selections = (*filter)(j.document, queued_permutations);
		auto counter = 0;
		for (auto const & permutation : queued_permutations) {
			if (selections.count(counter) > 0) {
				auto & lastChild = permutation.back();
				int const len = !permutation.empty() ? lastChild.document_position + lastChild.consumed_character_count - myInfo.document_position : 0;
				enque_permutation(j, myInfo, len, permutation);
			}
			counter++;
		}
	}
	queued_permutations.clear();
}

} // namespace detail
} // namespace parlex
