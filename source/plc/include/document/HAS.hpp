﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_HAS_HPP
#define INCLUDED_HAS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct HAS {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x8B_t>,
		parlex::detail::document::text<literal_has_t>
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit HAS(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
			parlex::detail::document::text<literal_0xE20x880x8B_t>,
			parlex::detail::document::text<literal_has_t>
		> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	HAS(HAS const & other) = default;
	HAS(HAS && move) = default;

	static HAS build(parlex::detail::ast_node const & n);
	static parlex::detail::state_machine const & state_machine();

};


} // namespace plc



#endif //INCLUDED_HAS_HPP
