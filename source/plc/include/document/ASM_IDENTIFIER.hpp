// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_IDENTIFIER_HPP
#define INCLUDED_ASM_IDENTIFIER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IDENTIFIER;

struct ASM_IDENTIFIER {
	bool field_1;
	erased<IDENTIFIER> field_2;


	ASM_IDENTIFIER(
		bool const & field_1,
		erased<IDENTIFIER> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<ASM_IDENTIFIER> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_ASM_IDENTIFIER_HPP