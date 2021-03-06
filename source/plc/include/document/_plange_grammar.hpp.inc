﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLANGE_GRAMMAR_HPP
#define INCLUDED_PLANGE_GRAMMAR_HPP

#include "parlex/builder.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/grammar.hpp"

#include "_plange_literals.hpp"

namespace plc {

class plange_grammar : public parlex::detail::grammar {
public:
	static plange_grammar const & get() {
		static plange_grammar value;
		return value;
	}

	uint16_t const ADDITION;
	uint16_t const ADD_SUB;
	uint16_t const ALL;
	uint16_t const ALLOCATION;
	uint16_t const AND;
	uint16_t const ARGUMENT;
	uint16_t const ARGUMENT_PACK;
	uint16_t const ARRAY;
	uint16_t const ARRAY_INDEXER;
	uint16_t const ARRAY_INVOCATION;
	uint16_t const ASM_EXPRESSION;
	uint16_t const ASM_FUNCTION;
	uint16_t const ASM_IDENTIFIER;
	uint16_t const ASM_OP;
	uint16_t const ASM_PTR_ARITHMETIC_ATT;
	uint16_t const ASM_PTR_ARITHMETIC_ATT_REG;
	uint16_t const ASM_PTR_ARITHMETIC_INTEL;
	uint16_t const ASM_SCOPE;
	uint16_t const ASM_STATEMENT;
	uint16_t const ASSIGNMENT_CHAIN;
	uint16_t const ATTRIBUTE;
	uint16_t const BIJECTION;
	uint16_t const BINARY_ARITHMETIC_OP;
	uint16_t const BINARY_COLLECTION_OP;
	uint16_t const BINARY_LOGICAL_OP;
	uint16_t const BINARY_OP;
	uint16_t const BITWISE_OP;
	uint16_t const BIT_AND;
	uint16_t const BIT_NOT;
	uint16_t const BIT_OR;
	uint16_t const BIT_XOR;
	uint16_t const BLOCK;
	uint16_t const BOOL;
	uint16_t const BREAK;
	uint16_t const CARDINALITY;
	uint16_t const CAST;
	uint16_t const CASTS;
	uint16_t const CEILING;
	uint16_t const COMMENT;
	uint16_t const COMPLEMENT;
	uint16_t const COMPOSITION;
	uint16_t const COMPOUND;
	uint16_t const CONDITIONAL;
	uint16_t const CONSTRUCTIVE_OP;
	uint16_t const CONTINUE;
	uint16_t const CROSS_PRODUCT;
	uint16_t const DATE;
	uint16_t const DATE_TIME;
	uint16_t const DATE_YEAR_DAY;
	uint16_t const DATE_YEAR_MONTH_DAY;
	uint16_t const DECLARATION;
	uint16_t const DEFINITION;
	uint16_t const DELTA;
	uint16_t const DIMENSION;
	uint16_t const DIMENSIONAL_ANALYSIS_OP;
	uint16_t const DIMENSIONAL_NUMBER;
	uint16_t const DIVISION;
	uint16_t const DO;
	uint16_t const DOT_PRODUCT;
	uint16_t const DOWNCASTS;
	uint16_t const EMBEDDED_COMMENT;
	uint16_t const EMBEDDED_COMMENT_INTERIOR;
	uint16_t const EMBEDDED_NEWLINE_STRING;
	uint16_t const EMBEDDED_NEWLINE_STRING_INTERIOR;
	uint16_t const EMBEDDED_STRING;
	uint16_t const EMBEDDED_STRING_INTERIOR;
	uint16_t const END_OF_LINE_COMMENT;
	uint16_t const ENUM;
	uint16_t const ENUM_ELEMENT;
	uint16_t const EQUALITY_CHAIN;
	uint16_t const EQUALITY_CHAIN_LOOP;
	uint16_t const EXACTLY;
	uint16_t const EXISTS;
	uint16_t const EXISTS_ONE;
	uint16_t const EXPONENTIATION;
	uint16_t const EXPRESSION;
	uint16_t const EXTERN;
	uint16_t const FACTORIAL;
	uint16_t const FLOOR;
	uint16_t const FOR;
	uint16_t const FOR_COLLECTION;
	uint16_t const FREE;
	uint16_t const FUNCTION;
	uint16_t const FUNCTION_MODIFIER_0;
	uint16_t const FUNCTION_MODIFIER_1;
	uint16_t const FUNCTION_MODIFIER_2;
	uint16_t const FUNCTION_MODIFIER_3;
	uint16_t const FUNCTION_MODIFIER_4;
	uint16_t const FUNCTION_MODIFIER_ATOMIC;
	uint16_t const FUNCTION_MODIFIER_CALLING_CONVENTION;
	uint16_t const FUNCTION_MODIFIER_MODEL;
	uint16_t const FUNCTION_MODIFIER_PLATFORM;
	uint16_t const FUNCTION_MODIFIER_STABILITY;
	uint16_t const FUNCTION_MODIFIER_THROWING;
	uint16_t const GREATER_CHAIN;
	uint16_t const GREATER_CHAIN_LOOP;
	uint16_t const HAS;
	uint16_t const HEX;
	uint16_t const IC;
	uint16_t const ICR;
	uint16_t const IDENTIFIER;
	uint16_t const IF;
	uint16_t const IFF;
	uint16_t const IMPLEMENTS;
	uint16_t const IMPLICATION;
	uint16_t const IMPLICIT_TYPE_DEREFERENCE;
	uint16_t const IMPORT;
	uint16_t const IN;
	uint16_t const INEQUALITY;
	uint16_t const INHERITANCE_ITEM_PREFIX;
	uint16_t const INHERITANCE_LIST;
	uint16_t const INHERITS;
	uint16_t const INTEGER_DIVISION;
	uint16_t const INTERSECTION;
	uint16_t const INVOCATION;
	uint16_t const IS;
	uint16_t const KLEENE_STAR;
	uint16_t const LESSER_CHAIN;
	uint16_t const LESSER_CHAIN_LOOP;
	uint16_t const LIST;
	uint16_t const LOCK;
	uint16_t const LOOP;
	uint16_t const MAGNITUDE;
	uint16_t const MAP;
	uint16_t const MAPS_TO;
	uint16_t const MEMBER_ACCESS;
	uint16_t const MEMBER_OFFSET;
	uint16_t const MODULATION;
	uint16_t const MULTIPLICATION;
	uint16_t const MULTIPLICATIVE_OP;
	uint16_t const NAND;
	uint16_t const NEAREST_INTEGER;
	uint16_t const NEGATION;
	uint16_t const NON_FRACTIONAL;
	uint16_t const NON_NEG_FRACTIONAL;
	uint16_t const NON_NEG_INTEGER;
	uint16_t const NON_NEG_NON_FRACTIONAL;
	uint16_t const NON_NEG_NUMBER;
	uint16_t const NON_ZERO_DECIMAL_DIGIT;
	uint16_t const NOR;
	uint16_t const NOT;
	uint16_t const NOT_HAS;
	uint16_t const NOT_IN;
	uint16_t const NULL_COALESCE;
	uint16_t const OBJECT;
	uint16_t const OCTAL;
	uint16_t const OR;
	uint16_t const PARAMETER;
	uint16_t const PARAMETER_ANALYTIC;
	uint16_t const PARAMETER_NATURAL;
	uint16_t const PARENTHETICAL;
	uint16_t const PARENTHETICAL_INVOCATION;
	uint16_t const PAYLOAD;
	uint16_t const PLATFORM;
	uint16_t const POST_DEC;
	uint16_t const POST_INC;
	uint16_t const PREPEND;
	uint16_t const PRE_DEC;
	uint16_t const PRE_INC;
	uint16_t const RADICAL;
	uint16_t const RANGE;
	uint16_t const READ_LOCK;
	uint16_t const RECORD;
	uint16_t const REGEX;
	uint16_t const RELATIONAL_COLLECTION_OP;
	uint16_t const RELATIONAL_OP;
	uint16_t const RETURN;
	uint16_t const SET;
	uint16_t const SET_COMPREHENSION;
	uint16_t const SHIFTL;
	uint16_t const SHIFTR;
	uint16_t const SLICE;
	uint16_t const STATEMENT;
	uint16_t const STATEMENT_SCOPE;
	uint16_t const STATIC;
	uint16_t const SUBSET_CHAIN;
	uint16_t const SUBSET_CHAIN_LOOP;
	uint16_t const SUBTRACTION;
	uint16_t const SUPERSET_CHAIN;
	uint16_t const SUPERSET_CHAIN_LOOP;
	uint16_t const SWIZZLE;
	uint16_t const SYMMETRIC_DIFFERENCE;
	uint16_t const THIS;
	uint16_t const THIS_FUNC;
	uint16_t const THIS_TYPE;
	uint16_t const THROW;
	uint16_t const TIME;
	uint16_t const TRY;
	uint16_t const TUPLE;
	uint16_t const TYPE;
	uint16_t const TYPE_CONSTRAINT;
	uint16_t const TYPE_CONSTRAINT_CHAIN;
	uint16_t const TYPE_CONSTRAINT_HEAD;
	uint16_t const TYPE_DEREFERENCE;
	uint16_t const TYPE_INVOCATION;
	uint16_t const TYPE_SCOPE;
	uint16_t const TYPE_SCOPE_ASSIGNMENT_CHAIN;
	uint16_t const TYPE_SCOPE_DECLARATION;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN;
	uint16_t const TYPE_STATEMENT;
	uint16_t const UNARY_ARITHMETIC_OP;
	uint16_t const UNARY_LOGICAL_OP;
	uint16_t const UNARY_OP;
	uint16_t const UNION;
	uint16_t const UNIT_DIVISION;
	uint16_t const UNIT_EXPONENTIATION;
	uint16_t const UNIT_MULTIPLICATION;
	uint16_t const UPCASTS;
	uint16_t const USING;
	uint16_t const VECTOR_NORM;
	uint16_t const VISIBILITY_MODIFIER;
	uint16_t const VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
	uint16_t const VOLATILE_TYPE_DEREFERENCE;
	uint16_t const WHOLE_NUMBER;
	uint16_t const WRITE_LOCK;
	uint16_t const WS;
	uint16_t const XML_DOC_STRING;
	uint16_t const XML_DOC_STRING_INTERIOR;
	uint16_t const XOR;
private:
	plange_grammar();

};

} // namespace plc



#endif //INCLUDED_PLANGE_GRAMMAR_HPP
