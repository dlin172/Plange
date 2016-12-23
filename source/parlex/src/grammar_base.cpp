#include "parlex/grammar_base.hpp"

namespace parlex {

void grammar_base::add_precedence(state_machine_base const & productionA, state_machine_base const & productionB) {
	precedences[&productionA].insert(&productionB);
}

bool grammar_base::test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const {
	auto i = precedences.find(&productionA);
	if (i == precedences.end()) {
		return false;
	}
	return i->second.count(&productionB) > 0;
}

precedence_collection const & grammar_base::get_precedences() const {
	return precedences;
}

}
