// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXPRESSION_HPP
#define INCLUDED_EXPRESSION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ARRAY;
struct ASM_FUNCTION;
struct BINARY_OP;
struct BOOL;
struct CAST;
struct CEILING;
struct COMPLEMENT;
struct CONDITIONAL;
struct DATE;
struct DATE_TIME;
struct DELTA;
struct DIMENSIONAL_NUMBER;
struct EMBEDDED_STRING;
struct ENUM;
struct EQUALITY_CHAIN;
struct FLOOR;
struct FUNCTION;
struct GREATER_CHAIN;
struct IDENTIFIER;
struct IF;
struct INVOCATION;
struct LESSER_CHAIN;
struct LIST;
struct MAGNITUDE;
struct MAP;
struct MEMBER_ACCESS;
struct NEAREST_INTEGER;
struct NON_NEG_NUMBER;
struct OBJECT;
struct PARENTHETICAL;
struct RANGE;
struct REGEX;
struct SET;
struct SET_COMPREHENSION;
struct STRING;
struct SUBSET_CHAIN;
struct SUPERSET_CHAIN;
struct SWIZZLE;
struct THIS;
struct THIS_FUNC;
struct THIS_TYPE;
struct TIME;
struct TUPLE;
struct TYPE;
struct UNARY_OP;
struct VECTOR_NORM;

typedef std::variant<
	erased<ARRAY>,
	erased<ASM_FUNCTION>,
	erased<BINARY_OP>,
	erased<BOOL>,
	erased<CAST>,
	erased<CEILING>,
	erased<COMPLEMENT>,
	erased<CONDITIONAL>,
	erased<DATE>,
	erased<DATE_TIME>,
	erased<DELTA>,
	erased<DIMENSIONAL_NUMBER>,
	erased<EMBEDDED_STRING>,
	erased<ENUM>,
	erased<EQUALITY_CHAIN>,
	erased<FLOOR>,
	erased<FUNCTION>,
	erased<GREATER_CHAIN>,
	erased<IDENTIFIER>,
	erased<IF>,
	erased<INVOCATION>,
	erased<LESSER_CHAIN>,
	erased<LIST>,
	erased<MAGNITUDE>,
	erased<MAP>,
	erased<MEMBER_ACCESS>,
	erased<NEAREST_INTEGER>,
	erased<NON_NEG_NUMBER>,
	erased<OBJECT>,
	erased<PARENTHETICAL>,
	erased<RANGE>,
	erased<REGEX>,
	erased<SET>,
	erased<SET_COMPREHENSION>,
	erased<STRING>,
	erased<SUBSET_CHAIN>,
	erased<SUPERSET_CHAIN>,
	erased<SWIZZLE>,
	erased<THIS>,
	erased<THIS_FUNC>,
	erased<THIS_TYPE>,
	erased<TIME>,
	erased<TUPLE>,
	erased<TYPE>,
	erased<UNARY_OP>,
	erased<VECTOR_NORM>,
	literal_context_t,
	literal_null_t
> EXPRESSION_base;

struct EXPRESSION: EXPRESSION_base {
	static std::optional<EXPRESSION> build(std::vector<parlex::details::match>::iterator & i);
	explicit EXPRESSION(EXPRESSION_base const & value) : EXPRESSION_base(value) {}
};
} // namespace plc



#endif //INCLUDED_EXPRESSION_HPP