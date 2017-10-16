// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_COMMENT_HPP
#define INCLUDED_EMBEDDED_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_COMMENT_INTERIOR;

struct EMBEDDED_COMMENT {
	erased<EMBEDDED_COMMENT_INTERIOR> field_1;
	


	explicit EMBEDDED_COMMENT(
		erased<EMBEDDED_COMMENT_INTERIOR> && field_1) : field_1(std::move(field_1)) {}

	EMBEDDED_COMMENT(EMBEDDED_COMMENT const & other) = default;
	EMBEDDED_COMMENT(EMBEDDED_COMMENT && move) = default;

	static EMBEDDED_COMMENT build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_EMBEDDED_COMMENT_HPP
