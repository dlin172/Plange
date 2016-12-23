#include "parlex/state_machine_base.hpp"

namespace parlex {

state_machine_base::state_machine_base(std::string const & id, size_t startState, associativity assoc) : recognizer(id), start_state(startState), filter(nullptr), assoc(assoc) { }

state_machine_base::state_machine_base(std::string const & id, size_t startState, filter_function const* filter, associativity assoc) : recognizer(id), start_state(startState), filter(filter), assoc(assoc) {}

void state_machine_base::start(details::subjob& sj, size_t documentPosition) const {
	process(sj.construct_start_state_context(documentPosition), start_state);
}


void state_machine_base::on(details::context_ref const & c, recognizer const & r, int nextDfaState) {
	c.owner().on(c, r, nextDfaState);
}


void state_machine_base::accept(details::context_ref const & c) {
	c.owner().accept(c);
}

}