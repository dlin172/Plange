﻿#include "_plange_grammar.hpp.inc"
#include "_plange_grammar_builder.cpp.inc"

plange_grammar::plange_grammar() : grammar(builder()),
			ADDITION(this->lookup_recognizer_index("ADDITION")),
			ADD_SUB(this->lookup_recognizer_index("ADD_SUB")),
			ALL(this->lookup_recognizer_index("ALL")),
			ALLOCATION(this->lookup_recognizer_index("ALLOCATION")),
			AND(this->lookup_recognizer_index("AND")),
			ARGUMENT(this->lookup_recognizer_index("ARGUMENT")),
			ARGUMENT_PACK(this->lookup_recognizer_index("ARGUMENT_PACK")),
			ARRAY(this->lookup_recognizer_index("ARRAY")),
			ARRAY_INDEXER(this->lookup_recognizer_index("ARRAY_INDEXER")),
			ARRAY_INVOCATION(this->lookup_recognizer_index("ARRAY_INVOCATION")),
			ASM_EXPRESSION(this->lookup_recognizer_index("ASM_EXPRESSION")),
			ASM_FUNCTION(this->lookup_recognizer_index("ASM_FUNCTION")),
			ASM_IDENTIFIER(this->lookup_recognizer_index("ASM_IDENTIFIER")),
			ASM_OP(this->lookup_recognizer_index("ASM_OP")),
			ASM_PTR_ARITHMETIC_ATT(this->lookup_recognizer_index("ASM_PTR_ARITHMETIC_ATT")),
			ASM_PTR_ARITHMETIC_ATT_REG(this->lookup_recognizer_index("ASM_PTR_ARITHMETIC_ATT_REG")),
			ASM_PTR_ARITHMETIC_INTEL(this->lookup_recognizer_index("ASM_PTR_ARITHMETIC_INTEL")),
			ASM_SCOPE(this->lookup_recognizer_index("ASM_SCOPE")),
			ASM_STATEMENT(this->lookup_recognizer_index("ASM_STATEMENT")),
			ASSIGNMENT_CHAIN(this->lookup_recognizer_index("ASSIGNMENT_CHAIN")),
			ATTRIBUTE(this->lookup_recognizer_index("ATTRIBUTE")),
			BIJECTION(this->lookup_recognizer_index("BIJECTION")),
			BINARY_ARITHMETIC_OP(this->lookup_recognizer_index("BINARY_ARITHMETIC_OP")),
			BINARY_COLLECTION_OP(this->lookup_recognizer_index("BINARY_COLLECTION_OP")),
			BINARY_LOGICAL_OP(this->lookup_recognizer_index("BINARY_LOGICAL_OP")),
			BINARY_OP(this->lookup_recognizer_index("BINARY_OP")),
			BITWISE_OP(this->lookup_recognizer_index("BITWISE_OP")),
			BIT_AND(this->lookup_recognizer_index("BIT_AND")),
			BIT_NOT(this->lookup_recognizer_index("BIT_NOT")),
			BIT_OR(this->lookup_recognizer_index("BIT_OR")),
			BIT_XOR(this->lookup_recognizer_index("BIT_XOR")),
			BLOCK(this->lookup_recognizer_index("BLOCK")),
			BOOL(this->lookup_recognizer_index("BOOL")),
			BREAK(this->lookup_recognizer_index("BREAK")),
			CARDINALITY(this->lookup_recognizer_index("CARDINALITY")),
			CAST(this->lookup_recognizer_index("CAST")),
			CASTS(this->lookup_recognizer_index("CASTS")),
			CEILING(this->lookup_recognizer_index("CEILING")),
			COMMENT(this->lookup_recognizer_index("COMMENT")),
			COMPLEMENT(this->lookup_recognizer_index("COMPLEMENT")),
			COMPOSITION(this->lookup_recognizer_index("COMPOSITION")),
			COMPOUND(this->lookup_recognizer_index("COMPOUND")),
			CONDITIONAL(this->lookup_recognizer_index("CONDITIONAL")),
			CONSTRUCTIVE_OP(this->lookup_recognizer_index("CONSTRUCTIVE_OP")),
			CONTINUE(this->lookup_recognizer_index("CONTINUE")),
			CROSS_PRODUCT(this->lookup_recognizer_index("CROSS_PRODUCT")),
			DATE(this->lookup_recognizer_index("DATE")),
			DATE_TIME(this->lookup_recognizer_index("DATE_TIME")),
			DATE_YEAR_DAY(this->lookup_recognizer_index("DATE_YEAR_DAY")),
			DATE_YEAR_MONTH_DAY(this->lookup_recognizer_index("DATE_YEAR_MONTH_DAY")),
			DECLARATION(this->lookup_recognizer_index("DECLARATION")),
			DEFINITION(this->lookup_recognizer_index("DEFINITION")),
			DELTA(this->lookup_recognizer_index("DELTA")),
			DIMENSION(this->lookup_recognizer_index("DIMENSION")),
			DIMENSIONAL_ANALYSIS_OP(this->lookup_recognizer_index("DIMENSIONAL_ANALYSIS_OP")),
			DIMENSIONAL_NUMBER(this->lookup_recognizer_index("DIMENSIONAL_NUMBER")),
			DIVISION(this->lookup_recognizer_index("DIVISION")),
			DO(this->lookup_recognizer_index("DO")),
			DOT_PRODUCT(this->lookup_recognizer_index("DOT_PRODUCT")),
			DOWNCASTS(this->lookup_recognizer_index("DOWNCASTS")),
			EMBEDDED_COMMENT(this->lookup_recognizer_index("EMBEDDED_COMMENT")),
			EMBEDDED_COMMENT_INTERIOR(this->lookup_recognizer_index("EMBEDDED_COMMENT_INTERIOR")),
			EMBEDDED_NEWLINE_STRING(this->lookup_recognizer_index("EMBEDDED_NEWLINE_STRING")),
			EMBEDDED_NEWLINE_STRING_INTERIOR(this->lookup_recognizer_index("EMBEDDED_NEWLINE_STRING_INTERIOR")),
			EMBEDDED_STRING(this->lookup_recognizer_index("EMBEDDED_STRING")),
			EMBEDDED_STRING_INTERIOR(this->lookup_recognizer_index("EMBEDDED_STRING_INTERIOR")),
			END_OF_LINE_COMMENT(this->lookup_recognizer_index("END_OF_LINE_COMMENT")),
			ENUM(this->lookup_recognizer_index("ENUM")),
			ENUM_ELEMENT(this->lookup_recognizer_index("ENUM_ELEMENT")),
			EQUALITY_CHAIN(this->lookup_recognizer_index("EQUALITY_CHAIN")),
			EQUALITY_CHAIN_LOOP(this->lookup_recognizer_index("EQUALITY_CHAIN_LOOP")),
			EXACTLY(this->lookup_recognizer_index("EXACTLY")),
			EXISTS(this->lookup_recognizer_index("EXISTS")),
			EXISTS_ONE(this->lookup_recognizer_index("EXISTS_ONE")),
			EXPONENTIATION(this->lookup_recognizer_index("EXPONENTIATION")),
			EXPRESSION(this->lookup_recognizer_index("EXPRESSION")),
			EXTERN(this->lookup_recognizer_index("EXTERN")),
			FACTORIAL(this->lookup_recognizer_index("FACTORIAL")),
			FLOOR(this->lookup_recognizer_index("FLOOR")),
			FOR(this->lookup_recognizer_index("FOR")),
			FOR_COLLECTION(this->lookup_recognizer_index("FOR_COLLECTION")),
			FREE(this->lookup_recognizer_index("FREE")),
			FUNCTION(this->lookup_recognizer_index("FUNCTION")),
			FUNCTION_MODIFIER_0(this->lookup_recognizer_index("FUNCTION_MODIFIER_0")),
			FUNCTION_MODIFIER_1(this->lookup_recognizer_index("FUNCTION_MODIFIER_1")),
			FUNCTION_MODIFIER_2(this->lookup_recognizer_index("FUNCTION_MODIFIER_2")),
			FUNCTION_MODIFIER_3(this->lookup_recognizer_index("FUNCTION_MODIFIER_3")),
			FUNCTION_MODIFIER_4(this->lookup_recognizer_index("FUNCTION_MODIFIER_4")),
			FUNCTION_MODIFIER_ATOMIC(this->lookup_recognizer_index("FUNCTION_MODIFIER_ATOMIC")),
			FUNCTION_MODIFIER_CALLING_CONVENTION(this->lookup_recognizer_index("FUNCTION_MODIFIER_CALLING_CONVENTION")),
			FUNCTION_MODIFIER_MODEL(this->lookup_recognizer_index("FUNCTION_MODIFIER_MODEL")),
			FUNCTION_MODIFIER_PLATFORM(this->lookup_recognizer_index("FUNCTION_MODIFIER_PLATFORM")),
			FUNCTION_MODIFIER_STABILITY(this->lookup_recognizer_index("FUNCTION_MODIFIER_STABILITY")),
			FUNCTION_MODIFIER_THROWING(this->lookup_recognizer_index("FUNCTION_MODIFIER_THROWING")),
			GREATER_CHAIN(this->lookup_recognizer_index("GREATER_CHAIN")),
			GREATER_CHAIN_LOOP(this->lookup_recognizer_index("GREATER_CHAIN_LOOP")),
			HAS(this->lookup_recognizer_index("HAS")),
			HEX(this->lookup_recognizer_index("HEX")),
			IC(this->lookup_recognizer_index("IC")),
			ICR(this->lookup_recognizer_index("ICR")),
			IDENTIFIER(this->lookup_recognizer_index("IDENTIFIER")),
			IF(this->lookup_recognizer_index("IF")),
			IFF(this->lookup_recognizer_index("IFF")),
			IMPLEMENTS(this->lookup_recognizer_index("IMPLEMENTS")),
			IMPLICATION(this->lookup_recognizer_index("IMPLICATION")),
			IMPLICIT_TYPE_DEREFERENCE(this->lookup_recognizer_index("IMPLICIT_TYPE_DEREFERENCE")),
			IMPORT(this->lookup_recognizer_index("IMPORT")),
			IN(this->lookup_recognizer_index("IN")),
			INEQUALITY(this->lookup_recognizer_index("INEQUALITY")),
			INHERITANCE_ITEM_PREFIX(this->lookup_recognizer_index("INHERITANCE_ITEM_PREFIX")),
			INHERITANCE_LIST(this->lookup_recognizer_index("INHERITANCE_LIST")),
			INHERITS(this->lookup_recognizer_index("INHERITS")),
			INTEGER_DIVISION(this->lookup_recognizer_index("INTEGER_DIVISION")),
			INTERSECTION(this->lookup_recognizer_index("INTERSECTION")),
			INVOCATION(this->lookup_recognizer_index("INVOCATION")),
			IS(this->lookup_recognizer_index("IS")),
			KLEENE_STAR(this->lookup_recognizer_index("KLEENE_STAR")),
			LESSER_CHAIN(this->lookup_recognizer_index("LESSER_CHAIN")),
			LESSER_CHAIN_LOOP(this->lookup_recognizer_index("LESSER_CHAIN_LOOP")),
			LIST(this->lookup_recognizer_index("LIST")),
			LOCK(this->lookup_recognizer_index("LOCK")),
			LOOP(this->lookup_recognizer_index("LOOP")),
			MAGNITUDE(this->lookup_recognizer_index("MAGNITUDE")),
			MAP(this->lookup_recognizer_index("MAP")),
			MAPS_TO(this->lookup_recognizer_index("MAPS_TO")),
			MEMBER_ACCESS(this->lookup_recognizer_index("MEMBER_ACCESS")),
			MEMBER_OFFSET(this->lookup_recognizer_index("MEMBER_OFFSET")),
			MODULATION(this->lookup_recognizer_index("MODULATION")),
			MULTIPLICATION(this->lookup_recognizer_index("MULTIPLICATION")),
			MULTIPLICATIVE_OP(this->lookup_recognizer_index("MULTIPLICATIVE_OP")),
			NAND(this->lookup_recognizer_index("NAND")),
			NEAREST_INTEGER(this->lookup_recognizer_index("NEAREST_INTEGER")),
			NEGATION(this->lookup_recognizer_index("NEGATION")),
			NON_FRACTIONAL(this->lookup_recognizer_index("NON_FRACTIONAL")),
			NON_NEG_FRACTIONAL(this->lookup_recognizer_index("NON_NEG_FRACTIONAL")),
			NON_NEG_INTEGER(this->lookup_recognizer_index("NON_NEG_INTEGER")),
			NON_NEG_NON_FRACTIONAL(this->lookup_recognizer_index("NON_NEG_NON_FRACTIONAL")),
			NON_NEG_NUMBER(this->lookup_recognizer_index("NON_NEG_NUMBER")),
			NON_ZERO_DECIMAL_DIGIT(this->lookup_recognizer_index("NON_ZERO_DECIMAL_DIGIT")),
			NOR(this->lookup_recognizer_index("NOR")),
			NOT(this->lookup_recognizer_index("NOT")),
			NOT_HAS(this->lookup_recognizer_index("NOT_HAS")),
			NOT_IN(this->lookup_recognizer_index("NOT_IN")),
			NULL_COALESCE(this->lookup_recognizer_index("NULL_COALESCE")),
			OBJECT(this->lookup_recognizer_index("OBJECT")),
			OCTAL(this->lookup_recognizer_index("OCTAL")),
			OR(this->lookup_recognizer_index("OR")),
			PARAMETER(this->lookup_recognizer_index("PARAMETER")),
			PARAMETER_ANALYTIC(this->lookup_recognizer_index("PARAMETER_ANALYTIC")),
			PARAMETER_NATURAL(this->lookup_recognizer_index("PARAMETER_NATURAL")),
			PARENTHETICAL(this->lookup_recognizer_index("PARENTHETICAL")),
			PARENTHETICAL_INVOCATION(this->lookup_recognizer_index("PARENTHETICAL_INVOCATION")),
			PAYLOAD(this->lookup_recognizer_index("PAYLOAD")),
			PLATFORM(this->lookup_recognizer_index("PLATFORM")),
			POST_DEC(this->lookup_recognizer_index("POST_DEC")),
			POST_INC(this->lookup_recognizer_index("POST_INC")),
			PREPEND(this->lookup_recognizer_index("PREPEND")),
			PRE_DEC(this->lookup_recognizer_index("PRE_DEC")),
			PRE_INC(this->lookup_recognizer_index("PRE_INC")),
			RADICAL(this->lookup_recognizer_index("RADICAL")),
			RANGE(this->lookup_recognizer_index("RANGE")),
			READ_LOCK(this->lookup_recognizer_index("READ_LOCK")),
			RECORD(this->lookup_recognizer_index("RECORD")),
			REGEX(this->lookup_recognizer_index("REGEX")),
			RELATIONAL_COLLECTION_OP(this->lookup_recognizer_index("RELATIONAL_COLLECTION_OP")),
			RELATIONAL_OP(this->lookup_recognizer_index("RELATIONAL_OP")),
			RETURN(this->lookup_recognizer_index("RETURN")),
			SET(this->lookup_recognizer_index("SET")),
			SET_COMPREHENSION(this->lookup_recognizer_index("SET_COMPREHENSION")),
			SHIFTL(this->lookup_recognizer_index("SHIFTL")),
			SHIFTR(this->lookup_recognizer_index("SHIFTR")),
			SLICE(this->lookup_recognizer_index("SLICE")),
			STATEMENT(this->lookup_recognizer_index("STATEMENT")),
			STATEMENT_SCOPE(this->lookup_recognizer_index("STATEMENT_SCOPE")),
			STATIC(this->lookup_recognizer_index("STATIC")),
			SUBSET_CHAIN(this->lookup_recognizer_index("SUBSET_CHAIN")),
			SUBSET_CHAIN_LOOP(this->lookup_recognizer_index("SUBSET_CHAIN_LOOP")),
			SUBTRACTION(this->lookup_recognizer_index("SUBTRACTION")),
			SUPERSET_CHAIN(this->lookup_recognizer_index("SUPERSET_CHAIN")),
			SUPERSET_CHAIN_LOOP(this->lookup_recognizer_index("SUPERSET_CHAIN_LOOP")),
			SWIZZLE(this->lookup_recognizer_index("SWIZZLE")),
			SYMMETRIC_DIFFERENCE(this->lookup_recognizer_index("SYMMETRIC_DIFFERENCE")),
			THIS(this->lookup_recognizer_index("THIS")),
			THIS_FUNC(this->lookup_recognizer_index("THIS_FUNC")),
			THIS_TYPE(this->lookup_recognizer_index("THIS_TYPE")),
			THROW(this->lookup_recognizer_index("THROW")),
			TIME(this->lookup_recognizer_index("TIME")),
			TRY(this->lookup_recognizer_index("TRY")),
			TUPLE(this->lookup_recognizer_index("TUPLE")),
			TYPE(this->lookup_recognizer_index("TYPE")),
			TYPE_CONSTRAINT(this->lookup_recognizer_index("TYPE_CONSTRAINT")),
			TYPE_CONSTRAINT_CHAIN(this->lookup_recognizer_index("TYPE_CONSTRAINT_CHAIN")),
			TYPE_CONSTRAINT_HEAD(this->lookup_recognizer_index("TYPE_CONSTRAINT_HEAD")),
			TYPE_DEREFERENCE(this->lookup_recognizer_index("TYPE_DEREFERENCE")),
			TYPE_INVOCATION(this->lookup_recognizer_index("TYPE_INVOCATION")),
			TYPE_SCOPE(this->lookup_recognizer_index("TYPE_SCOPE")),
			TYPE_SCOPE_ASSIGNMENT_CHAIN(this->lookup_recognizer_index("TYPE_SCOPE_ASSIGNMENT_CHAIN")),
			TYPE_SCOPE_DECLARATION(this->lookup_recognizer_index("TYPE_SCOPE_DECLARATION")),
			TYPE_SCOPE_TYPE_CONSTRAINT(this->lookup_recognizer_index("TYPE_SCOPE_TYPE_CONSTRAINT")),
			TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN(this->lookup_recognizer_index("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN")),
			TYPE_STATEMENT(this->lookup_recognizer_index("TYPE_STATEMENT")),
			UNARY_ARITHMETIC_OP(this->lookup_recognizer_index("UNARY_ARITHMETIC_OP")),
			UNARY_LOGICAL_OP(this->lookup_recognizer_index("UNARY_LOGICAL_OP")),
			UNARY_OP(this->lookup_recognizer_index("UNARY_OP")),
			UNION(this->lookup_recognizer_index("UNION")),
			UNIT_DIVISION(this->lookup_recognizer_index("UNIT_DIVISION")),
			UNIT_EXPONENTIATION(this->lookup_recognizer_index("UNIT_EXPONENTIATION")),
			UNIT_MULTIPLICATION(this->lookup_recognizer_index("UNIT_MULTIPLICATION")),
			UPCASTS(this->lookup_recognizer_index("UPCASTS")),
			USING(this->lookup_recognizer_index("USING")),
			VECTOR_NORM(this->lookup_recognizer_index("VECTOR_NORM")),
			VISIBILITY_MODIFIER(this->lookup_recognizer_index("VISIBILITY_MODIFIER")),
			VOLATILE_IMPLICIT_TYPE_DEREFERENCE(this->lookup_recognizer_index("VOLATILE_IMPLICIT_TYPE_DEREFERENCE")),
			VOLATILE_TYPE_DEREFERENCE(this->lookup_recognizer_index("VOLATILE_TYPE_DEREFERENCE")),
			WHOLE_NUMBER(this->lookup_recognizer_index("WHOLE_NUMBER")),
			WRITE_LOCK(this->lookup_recognizer_index("WRITE_LOCK")),
			WS(this->lookup_recognizer_index("WS")),
			XML_DOC_STRING(this->lookup_recognizer_index("XML_DOC_STRING")),
			XML_DOC_STRING_INTERIOR(this->lookup_recognizer_index("XML_DOC_STRING_INTERIOR")),
			XOR(this->lookup_recognizer_index("XOR"))
{}