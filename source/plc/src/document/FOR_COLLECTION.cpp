﻿// This file was generated using Parlex's cpp_generator

#include "FOR_COLLECTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"

plc::FOR_COLLECTION::declaration::field_1_t_1_t plc::FOR_COLLECTION::declaration::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		erased<TYPE_DEREFERENCE>,
		erased<IMPLICIT_TYPE_DEREFERENCE>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::FOR_COLLECTION::declaration plc::FOR_COLLECTION::declaration::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	return declaration(std::move(v0), std::move(v1));
}

plc::FOR_COLLECTION plc::FOR_COLLECTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_for_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::variant<
		declaration,
		erased<EXPRESSION>
	>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_in_t>,
		parlex::detail::document::text<literal_0xE20x880x88_t>
	>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[8], w);
	auto v9 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[9], w);
	auto v10 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[10], w);
	auto v11 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[11], w);
	auto v12 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[12], w);
	return FOR_COLLECTION(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6), std::move(v7), std::move(v8), std::move(v9), std::move(v10), std::move(v11), std::move(v12));
}


parlex::detail::state_machine const & plc::FOR_COLLECTION::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR_COLLECTION));
	return result;
}
