﻿// This file was generated using Parlex's cpp_generator

#include "RECORD.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ICR.hpp"
#include "TYPE.hpp"

plc::RECORD plc::RECORD::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_record_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<ICR>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<TYPE>>::build(&*children[2], w);
	return RECORD(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::state_machine const & plc::RECORD::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RECORD));
	return result;
}
