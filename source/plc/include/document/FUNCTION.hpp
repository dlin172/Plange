// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_HPP
#define INCLUDED_FUNCTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BLOCK;
struct FUNCTION_MODIFIER_0;
struct IC;
struct PARAMETER;

struct FUNCTION {
	struct field_1_t_1_t {
		struct field_2_t_1_t {
			struct field_1_t_1_t {
				std::vector<erased<IC>> field_1;
				
				std::vector<erased<IC>> field_2;
				
				erased<PARAMETER> parameter;
				
			
			
				explicit field_1_t_1_t(
					std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<PARAMETER> && parameter) : field_1(std::move(field_1)), field_2(std::move(field_2)), parameter(std::move(parameter)) {}
			
				field_1_t_1_t(field_1_t_1_t const & other) = default;
				field_1_t_1_t(field_1_t_1_t && move) = default;
			
				static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
			
			};
		
			erased<PARAMETER> parameter;
			
			std::vector<field_1_t_1_t> field_1;
			
			std::vector<erased<IC>> field_2;
			
		
		
			explicit field_2_t_1_t(
				erased<PARAMETER> && parameter, std::vector<field_1_t_1_t> && field_1, std::vector<erased<IC>> && field_2) : parameter(std::move(parameter)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		std::vector<erased<IC>> field_1;
		
		std::optional<field_2_t_1_t> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1, std::optional<field_2_t_1_t> && field_2, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_2_t_1_t {
		erased<FUNCTION_MODIFIER_0> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_2_t_1_t(
			erased<FUNCTION_MODIFIER_0> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::optional<field_1_t_1_t> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	
	erased<BLOCK> block;
	


	explicit FUNCTION(
		std::optional<field_1_t_1_t> && field_1, std::optional<field_2_t_1_t> && field_2, erased<BLOCK> && block) : field_1(std::move(field_1)), field_2(std::move(field_2)), block(std::move(block)) {}

	FUNCTION(FUNCTION const & other) = default;
	FUNCTION(FUNCTION && move) = default;

	static FUNCTION build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_HPP
