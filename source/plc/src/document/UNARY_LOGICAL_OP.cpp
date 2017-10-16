// This file was generated using Parlex's cpp_generator

#include "UNARY_LOGICAL_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ALL.hpp"
#include "EXISTS.hpp"
#include "EXISTS_ONE.hpp"
#include "NOT.hpp"

#include "UNARY_LOGICAL_OP.hpp"

namespace plc {

UNARY_LOGICAL_OP UNARY_LOGICAL_OP::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().UNARY_LOGICAL_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return UNARY_LOGICAL_OP(parlex::details::document::element<UNARY_LOGICAL_OP_base>::build(document, b, w));
}

} // namespace plc
