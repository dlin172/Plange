// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LESSER_CHAIN_HPP
#define INCLUDED_LESSER_CHAIN_HPP

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
struct LESSER_CHAIN_LOOP;

struct LESSER_CHAIN {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<LESSER_CHAIN_LOOP> field_3;
	


	explicit LESSER_CHAIN(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, erased<LESSER_CHAIN_LOOP> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	LESSER_CHAIN(LESSER_CHAIN const & other) = default;
	LESSER_CHAIN(LESSER_CHAIN && move) = default;

	static LESSER_CHAIN build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_LESSER_CHAIN_HPP
