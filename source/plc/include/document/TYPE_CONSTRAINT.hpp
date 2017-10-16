// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_HPP
#define INCLUDED_TYPE_CONSTRAINT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct TYPE_CONSTRAINT_CHAIN;
struct TYPE_CONSTRAINT_HEAD;

struct TYPE_CONSTRAINT {
	erased<TYPE_CONSTRAINT_HEAD> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<TYPE_CONSTRAINT_CHAIN> field_3;
	


	explicit TYPE_CONSTRAINT(
		erased<TYPE_CONSTRAINT_HEAD> && field_1, std::vector<erased<IC>> && field_2, erased<TYPE_CONSTRAINT_CHAIN> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	TYPE_CONSTRAINT(TYPE_CONSTRAINT const & other) = default;
	TYPE_CONSTRAINT(TYPE_CONSTRAINT && move) = default;

	static TYPE_CONSTRAINT build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_HPP
