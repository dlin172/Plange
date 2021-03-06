﻿// This file was generated using Parlex's cpp_generator

#include "UNARY_ARITHMETIC_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "FACTORIAL.hpp"
#include "NEGATION.hpp"
#include "POST_DEC.hpp"
#include "POST_INC.hpp"
#include "PRE_DEC.hpp"
#include "PRE_INC.hpp"
#include "RADICAL.hpp"

#include "UNARY_ARITHMETIC_OP.hpp"

namespace plc {

UNARY_ARITHMETIC_OP UNARY_ARITHMETIC_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return UNARY_ARITHMETIC_OP(parlex::detail::document::element<UNARY_ARITHMETIC_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::state_machine const & plc::UNARY_ARITHMETIC_OP::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNARY_ARITHMETIC_OP));
	return result;
}
