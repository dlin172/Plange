// This file was generated using Parlex's cpp_generator

#include "SUPERSET_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "SUPERSET_CHAIN_LOOP.hpp"

plc::SUPERSET_CHAIN plc::SUPERSET_CHAIN::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().SUPERSET_CHAIN.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<erased<SUPERSET_CHAIN_LOOP>>::build(document, *children[2], w);
	return SUPERSET_CHAIN(std::move(v_0), std::move(v_1), std::move(v_2));
}

