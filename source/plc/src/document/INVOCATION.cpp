﻿// This file was generated using Parlex's cpp_generator

#include "INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARRAY_INVOCATION.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "TYPE_INVOCATION.hpp"

#include "INVOCATION.hpp"

namespace plc {

INVOCATION INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return INVOCATION(parlex::detail::document::element<INVOCATION_base>::build(b, w));
}

} // namespace plc

parlex::detail::state_machine const & plc::INVOCATION::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INVOCATION));
	return result;
}
