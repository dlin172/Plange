// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TIME_HPP
#define INCLUDED_TIME_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct TIME {
	struct field_08_t_1_t {
		parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_1;
		
		std::vector<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>> field_2;
		
	
	
		explicit field_08_t_1_t(
			parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_1, std::vector<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_08_t_1_t(field_08_t_1_t const & other) = default;
		field_08_t_1_t(field_08_t_1_t && move) = default;
	
		static field_08_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_09_t_1_t_2_t {
		struct field_4_t_1_t {
			parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_1;
			
			parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_2;
			
		
		
			explicit field_4_t_1_t(
				parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_1, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_4_t_1_t(field_4_t_1_t const & other) = default;
			field_4_t_1_t(field_4_t_1_t && move) = default;
		
			static field_4_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		std::variant<
			literal_0x2B_t,
			literal_0x2D_t
		> field_1;
		
		parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_2;
		
		parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_3;
		
		std::optional<field_4_t_1_t> field_4;
		
	
	
		explicit field_09_t_1_t_2_t(
			std::variant<
				literal_0x2B_t,
				literal_0x2D_t
			> && field_1, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_2, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_3, std::optional<field_4_t_1_t> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}
	
		field_09_t_1_t_2_t(field_09_t_1_t_2_t const & other) = default;
		field_09_t_1_t_2_t(field_09_t_1_t_2_t && move) = default;
	
		static field_09_t_1_t_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	bool field_01;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_02;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_03;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_04;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_05;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_06;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_07;
	
	std::optional<field_08_t_1_t> field_08;
	
	std::optional<std::variant<
		literal_Z_t,
		field_09_t_1_t_2_t
	>> field_09;
	


	explicit TIME(
		bool && field_01, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_02, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_03, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_04, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_05, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_06, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_07, std::optional<field_08_t_1_t> && field_08, std::optional<std::variant<
			literal_Z_t,
			field_09_t_1_t_2_t
		>> && field_09) : field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), field_05(std::move(field_05)), field_06(std::move(field_06)), field_07(std::move(field_07)), field_08(std::move(field_08)), field_09(std::move(field_09)) {}

	TIME(TIME const & other) = default;
	TIME(TIME && move) = default;

	static TIME build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TIME_HPP
