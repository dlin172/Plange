﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
#define INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_1;
struct ICR;

struct FUNCTION_MODIFIER_STABILITY {
	struct field_1_t_1_t {
		erased<ICR> field_1;
		
		erased<FUNCTION_MODIFIER_1> field_2;
		
	
	
		explicit field_1_t_1_t(
			erased<ICR> && field_1, erased<FUNCTION_MODIFIER_1> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_stable_t>,
		parlex::detail::document::text<literal_unstable_t>
	> stability;
	
	std::optional<field_1_t_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_STABILITY(
		std::variant<
			parlex::detail::document::text<literal_stable_t>,
			parlex::detail::document::text<literal_unstable_t>
		> && stability, std::optional<field_1_t_1_t> && field_1) : stability(std::move(stability)), field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_STABILITY(FUNCTION_MODIFIER_STABILITY const & other) = default;
	FUNCTION_MODIFIER_STABILITY(FUNCTION_MODIFIER_STABILITY && move) = default;

	static FUNCTION_MODIFIER_STABILITY build(parlex::detail::ast_node const & n);
	static parlex::detail::state_machine const & state_machine();

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
