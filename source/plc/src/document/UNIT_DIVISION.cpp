// This file was generated using Parlex's cpp_generator

#include "UNIT_DIVISION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSION.hpp"

plc::UNIT_DIVISION plc::UNIT_DIVISION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().UNIT_DIVISION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<DIMENSION>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; /// 
	auto v_1 = parlex::details::document::element<erased<DIMENSION>>::build(document, *children[2], w);
	return UNIT_DIVISION(std::move(v_0), std::move(v_1));
}

