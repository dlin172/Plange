// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_HEX_HPP
#define INCLUDED_HEX_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct HEX {
	int field_2;


	HEX(
		int const & field_2
	) : field_2(field_2) {}

	static HEX build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_HEX_HPP
