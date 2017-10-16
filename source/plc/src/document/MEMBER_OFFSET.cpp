// This file was generated using Parlex's cpp_generator

#include "MEMBER_OFFSET.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "WHOLE_NUMBER.hpp"

plc::MEMBER_OFFSET plc::MEMBER_OFFSET::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().MEMBER_OFFSET.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //@ 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<WHOLE_NUMBER>>::build(document, *children[2], w);
	return MEMBER_OFFSET(std::move(v_0), std::move(v_1));
}

