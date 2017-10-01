// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNIT_DIVISION_HPP
#define INCLUDED_UNIT_DIVISION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct DIMENSION;

struct UNIT_DIVISION {
	erased<DIMENSION> field_1;
	erased<DIMENSION> field_2;


	UNIT_DIVISION(
		erased<DIMENSION> const & field_1,
		erased<DIMENSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<UNIT_DIVISION> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_UNIT_DIVISION_HPP