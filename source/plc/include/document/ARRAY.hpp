// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_HPP
#define INCLUDED_ARRAY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct ARRAY {
	std::vector<erased<IC>> field_1;
	std::optional<std::tuple<
		erased<EXPRESSION>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>>,
		std::vector<erased<IC>>
	>> field_2;


	ARRAY(
		std::vector<erased<IC>> const & field_1,
		std::optional<std::tuple<
			erased<EXPRESSION>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<EXPRESSION>
			>>,
			std::vector<erased<IC>>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static ARRAY build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ARRAY_HPP
