// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LIST_HPP
#define INCLUDED_LIST_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct LIST {
	struct elements_t_1_t {
		struct field_2_t_1_t {
			std::vector<erased<IC>> field_1;
			
			std::vector<erased<IC>> field_2;
			
			erased<EXPRESSION> field_3;
			
		
		
			explicit field_2_t_1_t(
				std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		erased<EXPRESSION> field_1;
		
		std::vector<field_2_t_1_t> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit elements_t_1_t(
			erased<EXPRESSION> && field_1, std::vector<field_2_t_1_t> && field_2, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		elements_t_1_t(elements_t_1_t const & other) = default;
		elements_t_1_t(elements_t_1_t && move) = default;
	
		static elements_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_1;
	
	std::optional<elements_t_1_t> elements;
	


	explicit LIST(
		std::vector<erased<IC>> && field_1, std::optional<elements_t_1_t> && elements) : field_1(std::move(field_1)), elements(std::move(elements)) {}

	LIST(LIST const & other) = default;
	LIST(LIST && move) = default;

	static LIST build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_LIST_HPP
