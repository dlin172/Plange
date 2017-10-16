// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_LOOP_HPP
#define INCLUDED_EQUALITY_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN_LOOP {
	struct field_2_t_1_t {
		std::vector<erased<IC>> field_1;
		
		erased<EQUALITY_CHAIN_LOOP> equality_chain_loop;
		
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1, erased<EQUALITY_CHAIN_LOOP> && equality_chain_loop) : field_1(std::move(field_1)), equality_chain_loop(std::move(equality_chain_loop)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> expression;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit EQUALITY_CHAIN_LOOP(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && expression, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	EQUALITY_CHAIN_LOOP(EQUALITY_CHAIN_LOOP const & other) = default;
	EQUALITY_CHAIN_LOOP(EQUALITY_CHAIN_LOOP && move) = default;

	static EQUALITY_CHAIN_LOOP build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_EQUALITY_CHAIN_LOOP_HPP
