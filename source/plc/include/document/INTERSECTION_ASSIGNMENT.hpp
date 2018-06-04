﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INTERSECTION_ASSIGNMENT_HPP
#define INCLUDED_INTERSECTION_ASSIGNMENT_HPP

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

struct INTERSECTION_ASSIGNMENT {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x880xA9_t> dontCare2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit INTERSECTION_ASSIGNMENT(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0xE20x880xA9_t> && dontCare2, std::variant<
			parlex::detail::document::text<literal_0x3C0x2D_t>,
			parlex::detail::document::text<literal_0xE20x860x90_t>
		> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	INTERSECTION_ASSIGNMENT(INTERSECTION_ASSIGNMENT const & other) = default;
	INTERSECTION_ASSIGNMENT(INTERSECTION_ASSIGNMENT && move) = default;

	static INTERSECTION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_INTERSECTION_ASSIGNMENT_HPP