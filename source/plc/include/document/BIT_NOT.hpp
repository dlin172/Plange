// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BIT_NOT_HPP
#define INCLUDED_BIT_NOT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct BIT_NOT {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;


	BIT_NOT(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static BIT_NOT build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_BIT_NOT_HPP
