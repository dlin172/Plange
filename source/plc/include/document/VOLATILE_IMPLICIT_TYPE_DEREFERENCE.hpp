// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;

struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;
	
	std::vector<erased<IC>> field_2;
	


	explicit VOLATILE_IMPLICIT_TYPE_DEREFERENCE(
		std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	VOLATILE_IMPLICIT_TYPE_DEREFERENCE(VOLATILE_IMPLICIT_TYPE_DEREFERENCE const & other) = default;
	VOLATILE_IMPLICIT_TYPE_DEREFERENCE(VOLATILE_IMPLICIT_TYPE_DEREFERENCE && move) = default;

	static VOLATILE_IMPLICIT_TYPE_DEREFERENCE build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
