﻿// This file was generated using Parlex's cpp_generator

#include "COMPLEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::COMPLEMENT plc::COMPLEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE10xB60x9C_t>>::build(&*children[2], w);
	return COMPLEMENT(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::state_machine const & plc::COMPLEMENT::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().COMPLEMENT));
	return result;
}
