﻿// This file was generated using Parlex's cpp_generator

#include "LESSER_CHAIN_LOOP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "LESSER_CHAIN_LOOP.hpp"

plc::LESSER_CHAIN_LOOP::field_4_t_1_t plc::LESSER_CHAIN_LOOP::field_4_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<LESSER_CHAIN_LOOP>>::build(&*children[1], w);
	return field_4_t_1_t(std::move(v0), std::move(v1));
}

plc::LESSER_CHAIN_LOOP plc::LESSER_CHAIN_LOOP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0x3C_t>,
		parlex::detail::document::text<literal_0x3D0x3C_t>,
		parlex::detail::document::text<literal_0xE20x890xA4_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_4_t_1_t>>::build(&*children[3], w);
	return LESSER_CHAIN_LOOP(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}


parlex::detail::acceptor const & plc::LESSER_CHAIN_LOOP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().LESSER_CHAIN_LOOP));
	return result;
}
