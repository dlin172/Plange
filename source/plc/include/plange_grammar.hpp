parlex::builder::grammar("STATEMENT_SCOPE", {
production("ADDITION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("+"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("ADD_SUB", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("±"),
				literal("+-")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("ALL", sequence({
			choice({
				literal("∀"),
				literal("all")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("ALLOCATION", sequence({
			literal("alloc"),
			repetition(
				reference("IC")
			),
			reference("PARENTHETICAL_INVOCATION")
		})),
production("AND", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("∧"),
				literal("and")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any, filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", }),
production("ARGUMENT", reference("EXPRESSION")),
production("ARGUMENT_PACK", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("...")
		})),
production("ARRAY", sequence({
			literal("["),
			repetition(
				reference("IC")
			),
			optional(
				sequence({
					reference("EXPRESSION", "EXPRESSION"),
					repetition(
						sequence({
							repetition(
								reference("IC")
							),
							literal(","),
							repetition(
								reference("IC")
							),
							reference("EXPRESSION", "EXPRESSION")
						})
					),
					repetition(
						reference("IC")
					)
				})
			),
			literal("]")
		})),
production("ARRAY_INDEXER", sequence({
			repetition(
				reference("IC")
			),
			choice({
				reference("ARGUMENT"),
				reference("ARGUMENT_PACK"),
				reference("SLICE")
			})
		})),
production("ARRAY_INVOCATION", sequence({
			reference("EXPRESSION"),
			literal("["),
			optional(
				reference("ARRAY_INDEXER", "ARRAY_INDEXER")
			),
			repetition(
				sequence({
					repetition(
						reference("IC")
					),
					literal(","),
					optional(
						reference("ARRAY_INDEXER", "ARRAY_INDEXER")
					)
				})
			),
			repetition(
				reference("IC")
			),
			literal("]")
		})),
production("ASM_EXPRESSION", choice({
			reference("ASM_IDENTIFIER"),
			reference("ASM_PTR_ARITHMETIC_ATT"),
			reference("ASM_PTR_ARITHMETIC_INTEL"),
			reference("NON_FRACTIONAL")
		})),
production("ASM_FUNCTION", sequence({
			optional(
				sequence({
					literal("("),
					repetition(
						reference("IC")
					),
					optional(
						sequence({
							reference("PARAMETER"),
							repetition(
								sequence({
									repetition(
										reference("IC")
									),
									literal(","),
									repetition(
										reference("IC")
									),
									reference("PARAMETER")
								})
							),
							repetition(
								reference("IC")
							)
						})
					),
					literal(")"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				reference("FUNCTION_MODIFIER_0")
			),
			literal("asm"),
			repetition(
				reference("IC")
			),
			literal("{"),
			reference("ASM_SCOPE"),
			literal("}")
		})),
production("ASM_IDENTIFIER", sequence({
			optional(
				literal("%")
			),
			reference("IDENTIFIER")
		})),
production("ASM_OP", sequence({
			reference("lowercase_letter"),
			repetition(
				reference("lowercase_letter")
			)
		})),
production("ASM_PTR_ARITHMETIC_ATT", choice({
			sequence({
				reference("ASM_IDENTIFIER"),
				literal(":"),
				reference("NON_FRACTIONAL")
			}),
			sequence({
				reference("ASM_IDENTIFIER"),
				literal(":"),
				reference("NON_FRACTIONAL"),
				reference("ASM_PTR_ARITHMETIC_ATT_REG")
			}),
			sequence({
				reference("NON_FRACTIONAL"),
				reference("ASM_PTR_ARITHMETIC_ATT_REG")
			})
		})),
production("ASM_PTR_ARITHMETIC_ATT_REG", sequence({
			literal("("),
			optional(
				reference("ASM_IDENTIFIER")
			),
			optional(
				sequence({
					literal(","),
					reference("ASM_IDENTIFIER"),
					optional(
						sequence({
							literal(","),
							reference("NON_NEG_NON_FRACTIONAL")
						})
					)
				})
			),
			literal(")")
		})),
production("ASM_PTR_ARITHMETIC_INTEL", sequence({
			optional(
				sequence({
					choice({
						literal("BYTE"),
						literal("WORD"),
						literal("DWORD"),
						literal("QWORD")
					}),
					literal(" PTR")
				})
			),
			literal("["),
			optional(
				sequence({
					reference("ASM_IDENTIFIER"),
					literal(":")
				})
			),
			reference("ASM_IDENTIFIER"),
			optional(
				sequence({
					literal("+"),
					reference("ASM_IDENTIFIER"),
					optional(
						sequence({
							literal("*"),
							reference("NON_NEG_NON_FRACTIONAL")
						})
					)
				})
			),
			optional(
				sequence({
					choice({
						literal("+"),
						literal("-")
					}),
					reference("NON_NEG_INTEGER")
				})
			),
			literal("]")
		})),
production("ASM_SCOPE", repetition(
			choice({
				reference("IC"),
				reference("ASM_STATEMENT")
			})
		)),
production("ASM_STATEMENT", sequence({
			reference("ASM_OP"),
			optional(
				sequence({
					reference("ICR"),
					reference("ASM_EXPRESSION"),
					repetition(
						sequence({
							repetition(
								reference("IC")
							),
							literal(","),
							optional(
								sequence({
									repetition(
										reference("IC")
									),
									reference("ASM_EXPRESSION")
								})
							)
						})
					)
				})
			),
			repetition(
				reference("IC")
			),
			literal("\n")
		})),
production("ASSIGNMENT_CHAIN", sequence({
			optional(
				sequence({
					reference("XML_DOC_STRING", "XML_DOC_STRING"),
					repetition(
						reference("IC")
					)
				})
			),
			reference("IDENTIFIER", "IDENTIFIER"),
			repetition(
				reference("IC")
			),
			choice({
				literal("←"),
				literal("<-")
			}),
			repetition(
				reference("IC")
			),
			choice({
				reference("EXPRESSION", "EXPRESSION"),
				reference("ASSIGNMENT_CHAIN")
			})
		}),
		associativity::none, filter_function(), {"EXPRESSION", "LESSER_CHAIN", }),
production("ATTRIBUTE", sequence({
			literal("@"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("@")
		})),
production("BIJECTION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("↔"),
				literal("<->")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("BINARY_ARITHMETIC_OP", choice({
			reference("ADD_SUB"),
			reference("ADDITION"),
			reference("DIVISION"),
			reference("EXPONENTIATION"),
			reference("INTEGER_DIVISION"),
			reference("MODULATION"),
			reference("MULTIPLICATIVE_OP"),
			reference("SHIFTL"),
			reference("SHIFTR"),
			reference("SUBTRACTION")
		})),
production("BINARY_COLLECTION_OP", choice({
			reference("BIJECTION"),
			reference("INTERSECTION"),
			reference("SYMMETRIC_DIFFERENCE"),
			reference("UNION")
		})),
production("BINARY_LOGICAL_OP", choice({
			reference("AND"),
			reference("IFF"),
			reference("IMPLICATION"),
			reference("MAPS_TO"),
			reference("NAND"),
			reference("NOR"),
			reference("OR"),
			reference("XOR")
		})),
production("BINARY_OP", choice({
			reference("BINARY_ARITHMETIC_OP"),
			reference("BINARY_COLLECTION_OP"),
			reference("BINARY_LOGICAL_OP"),
			reference("BITWISE_OP"),
			reference("CONSTRUCTIVE_OP"),
			reference("RELATIONAL_OP")
		})),
production("BITWISE_OP", choice({
			reference("BIT_AND"),
			reference("BIT_OR"),
			reference("BIT_XOR")
		})),
production("BIT_AND", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("&&"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("BIT_NOT", sequence({
			literal("~~"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("BIT_OR", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("||"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("BIT_XOR", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("^^"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("BLOCK", sequence({
			literal("{"),
			reference("STATEMENT_SCOPE"),
			literal("}")
		})),
production("BOOL", choice({
			literal("true"),
			literal("false")
		})),
production("BREAK", sequence({
			literal("break"),
			optional(
				choice({
					sequence({
						repetition(
							reference("IC")
						),
						literal("["),
						repetition(
							reference("IC")
						),
						reference("EXPRESSION", "EXPRESSION"),
						repetition(
							reference("IC")
						),
						literal("]")
					}),
					sequence({
						repetition(
							reference("ICR")
						),
						reference("IDENTIFIER", "IDENTIFIER")
					})
				})
			)
		})),
production("CARDINALITY", sequence({
			literal("#"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", }),
production("CAST", sequence({
			reference("PARENTHETICAL"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", }),
production("CASTS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("casts"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("CEILING", choice({
			sequence({
				literal("⌈"),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("⌉")
			}),
			sequence({
				literal("|\'"),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("\'|")
			})
		})),
production("COMMENT", sequence({
			literal("/*"),
			repetition(
				reference("all")
			),
			literal("*/")
		})),
production("COMPLEMENT", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("ᶜ")
		}),
		associativity::none, filter_function(), {"BINARY_OP", }),
production("COMPOSITION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("∘"),
				literal("_o_")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("COMPOUND", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("|"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("CONDITIONAL", sequence({
			reference("condition", "EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("\?"),
			repetition(
				reference("IC")
			),
			reference("true_case", "EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(":"),
			repetition(
				reference("IC")
			),
			reference("false_case", "EXPRESSION")
		}),
		associativity::right),
production("CONSTRUCTIVE_OP", choice({
			reference("COMPOSITION"),
			reference("COMPOUND"),
			reference("PREPEND"),
			reference("NULL_COALESCE")
		})),
production("CONTINUE", sequence({
			literal("continue"),
			optional(
				choice({
					sequence({
						repetition(
							reference("IC")
						),
						literal("["),
						repetition(
							reference("IC")
						),
						reference("EXPRESSION", "EXPRESSION"),
						repetition(
							reference("IC")
						),
						literal("]")
					}),
					sequence({
						repetition(
							reference("ICR")
						),
						reference("IDENTIFIER", "IDENTIFIER")
					})
				})
			)
		})),
production("CROSS_PRODUCT", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("×"),
				literal("_x_")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left, filter_function(), {"DOT_PRODUCT", }),
production("DATE", choice({
			reference("DATE_YEAR_MONTH_DAY"),
			reference("DATE_YEAR_DAY")
		})),
production("DATE_TIME", sequence({
			reference("DATE"),
			literal("T"),
			reference("TIME")
		})),
production("DATE_YEAR_DAY", sequence({
			reference("decimal_digit"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			literal("-"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			reference("decimal_digit")
		})),
production("DATE_YEAR_MONTH_DAY", sequence({
			reference("decimal_digit"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			literal("-"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			literal("-"),
			reference("decimal_digit"),
			reference("decimal_digit")
		}),
		associativity::none, filter_function(), {"SUBTRACTION", }),
production("DECLARATION", sequence({
			optional(
				sequence({
					reference("XML_DOC_STRING", "XML_DOC_STRING"),
					repetition(
						reference("IC")
					)
				})
			),
			reference("IDENTIFIER", "IDENTIFIER")
		})),
production("DEFINITION", sequence({
			optional(
				sequence({
					reference("XML_DOC_STRING", "XML_DOC_STRING"),
					repetition(
						reference("IC")
					)
				})
			),
			reference("IDENTIFIER", "IDENTIFIER"),
			repetition(
				reference("IC")
			),
			literal(":="),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION", "EXPRESSION")
		})),
production("DELTA", sequence({
			choice({
				literal("Δ"),
				literal("_delta_")
			}),
			optional(
				sequence({
					literal("^"),
					reference("WHOLE_NUMBER", "WHOLE_NUMBER")
				})
			),
			reference("EXPRESSION", "EXPRESSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", "EXPONENTIATION", }),
production("DIMENSION", choice({
			reference("IDENTIFIER"),
			reference("DIMENSIONAL_ANALYSIS_OP")
		})),
production("DIMENSIONAL_ANALYSIS_OP", choice({
			reference("UNIT_DIVISION"),
			reference("UNIT_EXPONENTIATION"),
			reference("UNIT_MULTIPLICATION")
		})),
production("DIMENSIONAL_NUMBER", sequence({
			reference("NON_NEG_NUMBER"),
			reference("DIMENSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", "EXPONENTIATION", }),
production("DIVISION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("÷"),
				literal("/")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left, filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MODULATION", "SUBTRACTION", }),
production("DO", sequence({
			literal("do"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION", "EXPRESSION"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					choice({
						literal("while"),
						literal("until")
					}),
					repetition(
						reference("IC")
					),
					reference("condition", "PARENTHETICAL")
				})
			)
		})),
production("DOT_PRODUCT", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("⋅"),
				literal("_dot_")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("DOWNCASTS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("downcasts"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("EMBEDDED_COMMENT", sequence({
			literal("/***"),
			reference("EMBEDDED_COMMENT_INTERIOR"),
			literal("***/")
		}),
		associativity::none, filter_function(), {"COMMENT", }),
production("EMBEDDED_COMMENT_INTERIOR", choice({
			reference("PAYLOAD"),
			sequence({
				literal("*"),
				reference("EMBEDDED_COMMENT_INTERIOR"),
				literal("*")
			})
		})),
production("EMBEDDED_NEWLINE_STRING", sequence({
			literal("\"\"\""),
			reference("EMBEDDED_NEWLINE_STRING_INTERIOR"),
			literal("\"\"\"")
		}),
		associativity::none, filter_function(), {"EMBEDDED_STRING", "STRING", }),
production("EMBEDDED_NEWLINE_STRING_INTERIOR", choice({
			sequence({
				literal("\n"),
				reference("PAYLOAD"),
				literal("\n")
			}),
			sequence({
				literal("\""),
				reference("EMBEDDED_NEWLINE_STRING_INTERIOR"),
				literal("\"")
			})
		})),
production("EMBEDDED_STRING", sequence({
			literal("\"\"\""),
			reference("EMBEDDED_STRING_INTERIOR"),
			literal("\"\"\"")
		}),
		associativity::none, filter_function(), {"STRING", }),
production("EMBEDDED_STRING_INTERIOR", choice({
			reference("PAYLOAD"),
			sequence({
				literal("\""),
				reference("EMBEDDED_STRING_INTERIOR"),
				literal("\"")
			})
		})),
production("END_OF_LINE_COMMENT", sequence({
			literal("//"),
			repetition(
				reference("not_newline")
			),
			literal("\n")
		})),
production("ENUM", sequence({
			literal("enum"),
			repetition(
				reference("IC")
			),
			optional(
				sequence({
					literal("inheriting"),
					repetition(
						reference("IC")
					),
					reference("INHERITANCE_LIST"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				sequence({
					literal("implementing"),
					repetition(
						reference("IC")
					),
					reference("INHERITANCE_LIST"),
					repetition(
						reference("IC")
					)
				})
			),
			literal("{"),
			optional(
				sequence({
					reference("ENUM_ELEMENT", "ENUM_ELEMENT"),
					repetition(
						sequence({
							repetition(
								reference("IC")
							),
							literal(";"),
							repetition(
								reference("IC")
							),
							reference("ENUM_ELEMENT", "ENUM_ELEMENT")
						})
					)
				})
			),
			literal("}")
		})),
production("ENUM_ELEMENT", sequence({
			reference("IDENTIFIER", "IDENTIFIER"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal(":="),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION", "EXPRESSION")
				})
			)
		})),
production("EQUALITY_CHAIN", sequence({
			reference("EXPRESSION", "EXPRESSION"),
			repetition(
				reference("IC")
			),
			reference("EQUALITY_CHAIN_LOOP", "EQUALITY_CHAIN_LOOP")
		}),
		associativity::none, filter_function(), {"GREATER_CHAIN", "LESSER_CHAIN", "SUBSET_CHAIN", "SUPERSET_CHAIN", }),
production("EQUALITY_CHAIN_LOOP", sequence({
			literal("="),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION", "EXPRESSION"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("EQUALITY_CHAIN_LOOP", "EQUALITY_CHAIN_LOOP")
				})
			)
		}),
		associativity::none, filter_function(), {"EXPRESSION", }),
production("EXACTLY", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("exactly"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("EXISTS", sequence({
			choice({
				literal("∃"),
				literal("exists")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("EXISTS_ONE", sequence({
			choice({
				literal("∃!"),
				literal("exists!")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("EXPONENTIATION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("^"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::right, filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", }),
production("EXPRESSION", choice({
			reference("ARRAY"),
			reference("ASM_FUNCTION"),
			reference("BINARY_OP"),
			reference("BOOL"),
			reference("CAST"),
			reference("CEILING"),
			reference("COMPLEMENT"),
			reference("CONDITIONAL"),
			reference("DATE"),
			reference("DATE_TIME"),
			reference("DELTA"),
			reference("DIMENSIONAL_NUMBER"),
			reference("EMBEDDED_STRING"),
			reference("ENUM"),
			reference("EQUALITY_CHAIN"),
			reference("FLOOR"),
			reference("FUNCTION"),
			reference("GREATER_CHAIN"),
			reference("IDENTIFIER"),
			reference("IF"),
			reference("INVOCATION"),
			reference("LESSER_CHAIN"),
			reference("LIST"),
			reference("MAGNITUDE"),
			reference("MAP"),
			reference("MEMBER_ACCESS"),
			reference("NEAREST_INTEGER"),
			reference("NON_NEG_NUMBER"),
			reference("OBJECT"),
			reference("PARENTHETICAL"),
			reference("RANGE"),
			reference("REGEX"),
			reference("SET"),
			reference("SET_COMPREHENSION"),
			reference("STRING"),
			reference("SUBSET_CHAIN"),
			reference("SUPERSET_CHAIN"),
			reference("SWIZZLE"),
			reference("THIS"),
			reference("THIS_FUNC"),
			reference("THIS_TYPE"),
			reference("TIME"),
			reference("TUPLE"),
			reference("TYPE"),
			reference("UNARY_OP"),
			reference("VECTOR_NORM"),
			literal("context"),
			literal("null")
		})),
production("FACTORIAL", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("!")
		}),
		associativity::none, filter_function(), {"BINARY_OP", }),
production("FLOOR", choice({
			sequence({
				literal("⌊"),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION", "EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("⌋")
			}),
			sequence({
				literal("|_"),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION", "EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("_|")
			})
		})),
production("FOR", sequence({
			literal("for"),
			repetition(
				reference("IC")
			),
			literal("("),
			repetition(
				reference("IC")
			),
			optional(
				sequence({
					reference("initializer", "STATEMENT_SCOPE"),
					repetition(
						reference("IC")
					)
				})
			),
			reference("condition", "EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(";"),
			repetition(
				reference("IC")
			),
			optional("step", 
				sequence({
					reference("ASSIGNMENT_CHAIN"),
					repetition(
						sequence({
							repetition(
								reference("IC")
							),
							literal(","),
							repetition(
								reference("IC")
							),
							reference("ASSIGNMENT_CHAIN")
						})
					),
					repetition(
						reference("IC")
					)
				})
			),
			literal(")"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("FOR_COLLECTION", sequence({
			literal("for"),
			repetition(
				reference("IC")
			),
			literal("("),
			repetition(
				reference("IC")
			),
			choice({
				sequence("declaration", {
					optional(
						sequence({
							choice({
								reference("TYPE_DEREFERENCE"),
								reference("IMPLICIT_TYPE_DEREFERENCE")
							}),
							repetition(
								reference("IC")
							)
						})
					),
					reference("IDENTIFIER")
				}),
				reference("EXPRESSION", "EXPRESSION")
			}),
			repetition(
				reference("IC")
			),
			choice({
				literal("in"),
				literal("∈")
			}),
			repetition(
				reference("IC")
			),
			reference("collection", "EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(")"),
			repetition(
				reference("IC")
			),
			reference("invoke", "EXPRESSION")
		})),
production("FREE", sequence({
			literal("free"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("FUNCTION", sequence({
			optional(
				sequence({
					literal("("),
					repetition(
						reference("IC")
					),
					optional(
						sequence({
							reference("PARAMETER", "PARAMETER"),
							repetition(
								sequence({
									repetition(
										reference("IC")
									),
									literal(","),
									repetition(
										reference("IC")
									),
									reference("PARAMETER", "PARAMETER")
								})
							),
							repetition(
								reference("IC")
							)
						})
					),
					literal(")"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				sequence({
					reference("FUNCTION_MODIFIER_0"),
					repetition(
						reference("IC")
					)
				})
			),
			reference("BLOCK", "BLOCK")
		}),
		associativity::none, filter_function(), {"CAST", }),
production("FUNCTION_MODIFIER_0", choice({
			reference("FUNCTION_MODIFIER_STABILITY"),
			reference("FUNCTION_MODIFIER_1")
		})),
production("FUNCTION_MODIFIER_1", choice({
			reference("FUNCTION_MODIFIER_THROWING"),
			reference("FUNCTION_MODIFIER_2")
		})),
production("FUNCTION_MODIFIER_2", choice({
			reference("FUNCTION_MODIFIER_ATOMIC"),
			reference("FUNCTION_MODIFIER_3")
		})),
production("FUNCTION_MODIFIER_3", choice({
			reference("FUNCTION_MODIFIER_PLATFORM"),
			reference("FUNCTION_MODIFIER_4")
		})),
production("FUNCTION_MODIFIER_4", choice({
			reference("FUNCTION_MODIFIER_MODEL"),
			reference("FUNCTION_MODIFIER_CALLING_CONVENTION")
		})),
production("FUNCTION_MODIFIER_ATOMIC", sequence({
			literal("atomic", "atomic"),
			optional(
				sequence({
					reference("ICR"),
					reference("FUNCTION_MODIFIER_3")
				})
			)
		})),
production("FUNCTION_MODIFIER_CALLING_CONVENTION", choice({
			literal("c_call"),
			literal("fast_call"),
			literal("cold_call"),
			literal("ghc_call"),
			literal("hipe_call"),
			literal("webkit_js_call"),
			literal("any_reg_call"),
			literal("preserve_most_call"),
			literal("preserve_all_call"),
			literal("swift_call"),
			literal("cxx_fast_tls_call"),
			literal("first_target_call"),
			literal("x86_std_call"),
			literal("X86_fast_call"),
			literal("arm_apcs_call"),
			literal("arm_aapcs_call"),
			literal("arm_aapcs_vfp_call"),
			literal("msp430_intr_call"),
			literal("x86_this_call"),
			literal("ptx_kernel_call"),
			literal("ptx_device_call"),
			literal("spir_func_call"),
			literal("spir_kernel_call"),
			literal("intel_ocl_bi_call"),
			literal("x86_64_sysv_call"),
			literal("x86_64_win64_call"),
			literal("x86_vector_call"),
			literal("hhvm_call"),
			literal("x86_intr_call"),
			literal("avr_intr_call"),
			literal("avr_signal_call"),
			literal("avr_builtin_call")
		})),
production("FUNCTION_MODIFIER_MODEL", sequence({
			choice("model", {
				literal("pure"),
				literal("imperative"),
				literal("opaque")
			}),
			optional(
				sequence({
					reference("ICR"),
					reference("FUNCTION_MODIFIER_CALLING_CONVENTION")
				})
			)
		})),
production("FUNCTION_MODIFIER_PLATFORM", sequence({
			reference("PLATFORM"),
			repetition(
				sequence({
					reference("ICR"),
					reference("PLATFORM")
				})
			),
			optional(
				sequence({
					reference("ICR"),
					reference("FUNCTION_MODIFIER_4")
				})
			)
		})),
production("FUNCTION_MODIFIER_STABILITY", sequence({
			choice("stability", {
				literal("stable"),
				literal("unstable")
			}),
			optional(
				sequence({
					reference("ICR"),
					reference("FUNCTION_MODIFIER_1")
				})
			)
		})),
production("FUNCTION_MODIFIER_THROWING", sequence({
			literal("throwing", "throwing"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("ARRAY")
				})
			),
			optional(
				sequence({
					reference("ICR"),
					reference("FUNCTION_MODIFIER_2")
				})
			)
		})),
production("GREATER_CHAIN", sequence({
			reference("EXPRESSION", "EXPRESSION"),
			repetition(
				reference("IC")
			),
			reference("GREATER_CHAIN_LOOP", "GREATER_CHAIN_LOOP")
		})),
production("GREATER_CHAIN_LOOP", sequence({
			choice({
				literal("="),
				literal(">"),
				literal("=>"),
				literal("≥")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION", "EXPRESSION"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("GREATER_CHAIN_LOOP", "GREATER_CHAIN_LOOP")
				})
			)
		}),
		associativity::none, filter_function(), {"EXPRESSION", }),
production("HAS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("∋"),
				literal("has")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("HEX", sequence({
			literal("0x"),
			reference("hexadecimal_digit"),
			repetition(
				reference("hexadecimal_digit")
			)
		})),
production("IC", choice({
			reference("COMMENT"),
			reference("EMBEDDED_COMMENT"),
			reference("END_OF_LINE_COMMENT"),
			reference("WS")
		})),
production("ICR", sequence({
			reference("IC"),
			repetition(
				reference("IC")
			)
		})),
production("IDENTIFIER", sequence({
			choice({
				reference("letter"),
				literal("_")
			}),
			repetition(
				choice({
					reference("letter"),
					reference("number"),
					literal("_")
				})
			)
		}),
		associativity::none, builtins.longest),
production("IF", sequence({
			literal("if"),
			repetition(
				reference("IC")
			),
			reference("condition", "PARENTHETICAL"),
			repetition(
				reference("IC")
			),
			reference("invoke", "EXPRESSION"),
			repetition(
				sequence({
					repetition(
						reference("IC")
					),
					literal("elif"),
					repetition(
						reference("IC")
					),
					reference("condition", "PARENTHETICAL"),
					repetition(
						reference("IC")
					),
					reference("invoke", "EXPRESSION")
				})
			),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("else"),
					repetition(
						reference("IC")
					),
					reference("else_invoke", "EXPRESSION")
				})
			)
		})),
production("IFF", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("⇔"),
				literal("<=>")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("IMPLEMENTS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("implements"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("IMPLICATION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("⇒"),
				literal("=>")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::right, filter_function(), {"IFF", "XOR", }),
production("IMPLICIT_TYPE_DEREFERENCE", sequence({
			literal("<"),
			repetition(
				reference("IC")
			),
			literal(">")
		})),
production("IMPORT", sequence({
			literal("import"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("IN", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("∈"),
				literal("in")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("INEQUALITY", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("≠"),
				literal("/=")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("INHERITANCE_ITEM_PREFIX", sequence({
			choice({
				reference("VISIBILITY_MODIFIER"),
				sequence({
					reference("VISIBILITY_MODIFIER"),
					reference("ICR"),
					literal("diamond", "diamond")
				}),
				literal("diamond", "diamond")
			}),
			reference("ICR")
		})),
production("INHERITANCE_LIST", sequence({
			optional(
				reference("INHERITANCE_ITEM_PREFIX")
			),
			reference("EXPRESSION", "EXPRESSION"),
			repetition(
				sequence({
					repetition(
						reference("IC")
					),
					literal(","),
					repetition(
						reference("IC")
					),
					optional(
						reference("INHERITANCE_ITEM_PREFIX")
					),
					reference("EXPRESSION", "EXPRESSION")
				})
			)
		})),
production("INHERITS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("inherits"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("INTEGER_DIVISION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("\\"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left, filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", }),
production("INTERSECTION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("∩"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("INVOCATION", choice({
			reference("PARENTHETICAL_INVOCATION"),
			reference("ARRAY_INVOCATION"),
			reference("TYPE_INVOCATION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", "NEGATION", "RADICAL", }),
production("IS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("is"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("KLEENE_STAR", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("*")
		})),
production("LESSER_CHAIN", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			reference("LESSER_CHAIN_LOOP")
		})),
production("LESSER_CHAIN_LOOP", sequence({
			choice({
				literal("="),
				literal("<"),
				literal("=<"),
				literal("≤")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("LESSER_CHAIN_LOOP")
				})
			)
		}),
		associativity::none, filter_function(), {"EXPRESSION", }),
production("LIST", sequence({
			literal("[|"),
			repetition(
				reference("IC")
			),
			optional(
				sequence({
					reference("EXPRESSION"),
					repetition(
						sequence({
							repetition(
								reference("IC")
							),
							literal(", "),
							repetition(
								reference("IC")
							),
							reference("EXPRESSION")
						})
					),
					repetition(
						reference("IC")
					)
				})
			),
			literal("|]")
		})),
production("LOCK", sequence({
			literal("lock"),
			repetition(
				reference("IC")
			),
			reference("PARENTHETICAL"),
			repetition(
				reference("IC")
			),
			reference("BLOCK")
		})),
production("LOOP", sequence({
			choice({
				literal("while"),
				literal("until")
			}),
			repetition(
				reference("IC")
			),
			reference("PARENTHETICAL"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("MAGNITUDE", sequence({
			literal("|"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("|")
		})),
production("MAP", sequence({
			literal("{"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("EXPRESSION"),
					repetition(
						reference("IC")
					),
					literal(":"),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION"),
					repetition(
						sequence({
							repetition(
								reference("IC")
							),
							literal(","),
							repetition(
								reference("IC")
							),
							reference("EXPRESSION"),
							repetition(
								reference("IC")
							),
							literal(":"),
							repetition(
								reference("IC")
							),
							reference("EXPRESSION")
						})
					)
				})
			),
			repetition(
				reference("IC")
			),
			literal("}")
		}),
		associativity::none, filter_function(), {"FUNCTION", }),
production("MAPS_TO", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("→"),
				literal("->")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::right),
production("MEMBER_ACCESS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("."),
			repetition(
				reference("IC")
			),
			reference("IDENTIFIER")
		}),
		associativity::left),
production("MEMBER_OFFSET", sequence({
			literal("@"),
			repetition(
				reference("IC")
			),
			reference("WHOLE_NUMBER")
		})),
production("MODULATION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("%"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left, filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", }),
production("MULTIPLICATION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("*"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any, filter_function(), {"MAPS_TO", }),
production("MULTIPLICATIVE_OP", choice({
			reference("CROSS_PRODUCT"),
			reference("DOT_PRODUCT"),
			reference("MULTIPLICATION")
		}),
		associativity::none, filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MODULATION", "SUBTRACTION", }),
production("NAND", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("↑"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left, filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", }),
production("NEAREST_INTEGER", choice({
			sequence({
				literal("⌊"),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("⌉")
			}),
			sequence({
				literal("|_"),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("\'|")
			})
		})),
production("NEGATION", sequence({
			literal("-"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", }),
production("NON_FRACTIONAL", sequence({
			optional(
				literal("-")
			),
			reference("NON_NEG_NON_FRACTIONAL")
		})),
production("NON_NEG_FRACTIONAL", choice({
			sequence({
				reference("decimal_digit"),
				repetition(
					reference("decimal_digit")
				),
				literal("."),
				repetition(
					reference("decimal_digit")
				)
			}),
			sequence({
				literal("."),
				reference("decimal_digit"),
				repetition(
					reference("decimal_digit")
				)
			})
		})),
production("NON_NEG_INTEGER", choice({
			sequence({
				reference("NON_ZERO_DECIMAL_DIGIT"),
				repetition(
					reference("decimal_digit")
				)
			}),
			literal("0")
		})),
production("NON_NEG_NON_FRACTIONAL", choice({
			reference("NON_NEG_INTEGER"),
			reference("HEX"),
			reference("OCTAL")
		})),
production("NON_NEG_NUMBER", choice({
			reference("NON_NEG_NON_FRACTIONAL"),
			reference("NON_NEG_FRACTIONAL")
		})),
production("NON_ZERO_DECIMAL_DIGIT", choice({
			literal("1"),
			literal("2"),
			literal("3"),
			literal("4"),
			literal("5"),
			literal("6"),
			literal("7"),
			literal("8"),
			literal("9")
		})),
production("NOR", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("↓"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left, filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", }),
production("NOT", sequence({
			choice({
				literal("¬"),
				literal("~")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", }),
production("NOT_HAS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("∌"),
				literal("/has")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("NOT_IN", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("∉"),
				literal("/in")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("NULL_COALESCE", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("\?\?"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("OBJECT", sequence({
			literal("object"),
			repetition(
				reference("IC")
			),
			optional(
				sequence({
					literal("inheriting"),
					repetition(
						reference("IC")
					),
					reference("INHERITANCE_LIST"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				sequence({
					literal("implementing"),
					repetition(
						reference("IC")
					),
					reference("INHERITANCE_LIST"),
					repetition(
						reference("IC")
					)
				})
			),
			literal("{"),
			reference("TYPE_SCOPE"),
			literal("}")
		})),
production("OCTAL", sequence({
			literal("0"),
			reference("octal_digit"),
			repetition(
				reference("octal_digit")
			)
		})),
production("OR", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("∨"),
				literal("or")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any, filter_function(), {"IFF", "IMPLICATION", "XOR", }),
production("PARAMETER", choice({
			reference("PARAMETER_NATURAL"),
			reference("PARAMETER_ANALYTIC")
		})),
production("PARAMETER_ANALYTIC", sequence({
			reference("EXPRESSION"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("="),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION")
				})
			)
		})),
production("PARAMETER_NATURAL", choice({
			sequence({
				optional(
					sequence({
						reference("TYPE_DEREFERENCE"),
						repetition(
							reference("IC")
						)
					})
				),
				reference("IDENTIFIER"),
				optional(
					literal("...")
				)
			}),
			sequence({
				optional(
					sequence({
						choice({
							reference("TYPE_DEREFERENCE"),
							reference("IMPLICIT_TYPE_DEREFERENCE")
						}),
						repetition(
							reference("IC")
						)
					})
				),
				reference("IDENTIFIER"),
				optional(
					literal("...")
				),
				repetition(
					reference("IC")
				),
				literal("="),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				optional(
					literal("...")
				)
			})
		}),
		associativity::none, filter_function(), {"PARAMETER_ANALYTIC", }),
production("PARENTHETICAL", sequence({
			literal("("),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(")")
		})),
production("PARENTHETICAL_INVOCATION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("("),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					choice({
						reference("ARGUMENT"),
						reference("ARGUMENT_PACK")
					})
				})
			),
			repetition(
				sequence({
					repetition(
						reference("IC")
					),
					literal(","),
					optional(
						sequence({
							repetition(
								reference("IC")
							),
							choice({
								reference("ARGUMENT"),
								reference("ARGUMENT_PACK")
							})
						})
					)
				})
			),
			repetition(
				reference("IC")
			),
			literal(")")
		})),
production("PAYLOAD", reference("all")),
production("PLATFORM", sequence({
			literal("_"),
			repetition(
				choice({
					reference("letter"),
					reference("number"),
					reference("PLATFORM")
				})
			)
		}),
		associativity::none, builtins.longest),
production("POST_DEC", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("--")
		}),
		associativity::none, filter_function(), {"BINARY_OP", "NEGATION", }),
production("POST_INC", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("++")
		}),
		associativity::none, filter_function(), {"BINARY_OP", "NEGATION", }),
production("PREPEND", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("&"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::right),
production("PRE_DEC", sequence({
			literal("--"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", "NEGATION", }),
production("PRE_INC", sequence({
			literal("++"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::none, filter_function(), {"BINARY_OP", "NEGATION", }),
production("RADICAL", sequence({
			literal("√"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::none, filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", }),
production("RANGE", choice({
			sequence({
				literal("("),
				repetition(
					reference("IC")
				),
				literal("..."),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				choice({
					literal("]"),
					literal(")")
				})
			}),
			sequence({
				choice({
					literal("["),
					literal("(")
				}),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("..."),
				repetition(
					reference("IC")
				),
				literal(")")
			}),
			sequence({
				choice({
					literal("("),
					literal("[")
				}),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				literal("..."),
				repetition(
					reference("IC")
				),
				reference("EXPRESSION"),
				repetition(
					reference("IC")
				),
				choice({
					literal("]"),
					literal(")")
				})
			})
		})),
production("READ_LOCK", sequence({
			literal("read_lock"),
			repetition(
				reference("IC")
			),
			reference("PARENTHETICAL"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("RECORD", sequence({
			literal("record"),
			repetition(
				reference("ICR")
			),
			reference("TYPE")
		})),
production("REGEX", sequence({
			literal("R"),
			reference("STRING")
		})),
production("RELATIONAL_COLLECTION_OP", choice({
			reference("HAS"),
			reference("IN"),
			reference("NOT_HAS"),
			reference("NOT_IN")
		})),
production("RELATIONAL_OP", choice({
			reference("CASTS"),
			reference("DOWNCASTS"),
			reference("EXACTLY"),
			reference("IMPLEMENTS"),
			reference("INEQUALITY"),
			reference("INHERITS"),
			reference("IS"),
			reference("RELATIONAL_COLLECTION_OP"),
			reference("UPCASTS")
		}),
		associativity::none, filter_function(), {"BINARY_LOGICAL_OP", }),
production("RETURN", sequence({
			literal("return"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("["),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION"),
					repetition(
						reference("IC")
					),
					literal("]")
				})
			),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("EXPRESSION")
				})
			)
		})),
production("SET", sequence({
			literal("{|"),
			repetition(
				reference("IC")
			),
			optional(
				sequence({
					reference("EXPRESSION"),
					repetition(
						sequence({
							repetition(
								reference("IC")
							),
							literal(","),
							repetition(
								reference("IC")
							),
							reference("EXPRESSION")
						})
					),
					repetition(
						reference("IC")
					)
				})
			),
			literal("|}")
		}),
		associativity::none, filter_function(), {"MAGNITUDE", }),
production("SET_COMPREHENSION", sequence({
			literal("{"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("|"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("}")
		})),
production("SHIFTL", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("<<"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("SHIFTR", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(">>"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("SLICE", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(":"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("STATEMENT", sequence({
			choice({
				reference("ASSIGNMENT_CHAIN"),
				reference("BREAK"),
				reference("CONTINUE"),
				reference("DEFINITION"),
				reference("DO"),
				reference("EXPRESSION"),
				reference("FOR"),
				reference("FOR_COLLECTION"),
				reference("FREE"),
				reference("IMPORT"),
				reference("LOCK"),
				reference("LOOP"),
				reference("READ_LOCK"),
				reference("RETURN"),
				reference("THROW"),
				reference("TRY"),
				reference("TYPE_CONSTRAINT"),
				reference("WRITE_LOCK"),
				reference("USING")
			}),
			repetition(
				reference("IC")
			),
			literal(";")
		})),
production("STATEMENT_SCOPE", repetition(
			choice({
				reference("IC"),
				reference("STATEMENT")
			})
		)),
production("STRING", reference("c_string")),
production("SUBSET_CHAIN", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			reference("SUBSET_CHAIN_LOOP")
		})),
production("SUBSET_CHAIN_LOOP", sequence({
			choice({
				literal("="),
				literal("⊆"),
				literal("subs"),
				literal("⊂"),
				literal("psubs")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("SUBSET_CHAIN_LOOP")
				})
			)
		}),
		associativity::none, filter_function(), {"EXPRESSION", }),
production("SUBTRACTION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("-"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("SUPERSET_CHAIN", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			reference("SUPERSET_CHAIN_LOOP")
		})),
production("SUPERSET_CHAIN_LOOP", sequence({
			choice({
				literal("="),
				literal("⊇"),
				literal("sups"),
				literal("⊃"),
				literal("psups")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("SUPERSET_CHAIN_LOOP")
				})
			)
		}),
		associativity::none, filter_function(), {"EXPRESSION", }),
production("SWIZZLE", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("⋮"),
				literal("_swiz_")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("SYMMETRIC_DIFFERENCE", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("⊖"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
production("THIS", sequence({
			literal("this"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("["),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION"),
					repetition(
						reference("IC")
					),
					literal("]")
				})
			)
		})),
production("THIS_FUNC", sequence({
			literal("this_func"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("["),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION"),
					repetition(
						reference("IC")
					),
					literal("]")
				})
			)
		})),
production("THIS_TYPE", sequence({
			literal("this_type"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("["),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION"),
					repetition(
						reference("IC")
					),
					literal("]")
				})
			)
		})),
production("THROW", sequence({
			literal("throw"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("["),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION"),
					repetition(
						reference("IC")
					),
					literal("]")
				})
			),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("EXPRESSION")
				})
			)
		})),
production("TIME", sequence({
			optional(
				literal("-")
			),
			reference("decimal_digit"),
			reference("decimal_digit"),
			literal(":"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			literal(":"),
			reference("decimal_digit"),
			reference("decimal_digit"),
			optional(
				sequence({
					literal("."),
					reference("decimal_digit"),
					repetition(
						reference("decimal_digit")
					)
				})
			),
			optional(
				choice({
					literal("Z"),
					sequence({
						choice({
							literal("+"),
							literal("-")
						}),
						reference("decimal_digit"),
						reference("decimal_digit"),
						optional(
							sequence({
								literal(":"),
								reference("decimal_digit"),
								reference("decimal_digit")
							})
						)
					})
				})
			)
		})),
production("TRY", sequence({
			literal("try"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("catch"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				sequence({
					literal("catch"),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION")
				})
			),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal("finally"),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION")
				})
			)
		})),
production("TUPLE", sequence({
			literal("(|"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				sequence({
					repetition(
						reference("IC")
					),
					literal(","),
					repetition(
						reference("IC")
					),
					reference("EXPRESSION")
				})
			),
			repetition(
				reference("IC")
			),
			literal("|)")
		}),
		associativity::none, filter_function(), {"MAGNITUDE", }),
production("TYPE", sequence({
			literal("type"),
			repetition(
				reference("IC")
			),
			optional(
				sequence({
					literal("inheriting"),
					repetition(
						reference("IC")
					),
					reference("INHERITANCE_LIST"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				sequence({
					literal("implementing"),
					repetition(
						reference("IC")
					),
					reference("INHERITANCE_LIST"),
					repetition(
						reference("IC")
					)
				})
			),
			literal("{"),
			reference("TYPE_SCOPE"),
			literal("}")
		})),
production("TYPE_CONSTRAINT", sequence({
			reference("TYPE_CONSTRAINT_HEAD"),
			repetition(
				reference("IC")
			),
			reference("TYPE_CONSTRAINT_CHAIN")
		})),
production("TYPE_CONSTRAINT_CHAIN", sequence({
			choice({
				reference("DECLARATION"),
				reference("ASSIGNMENT_CHAIN"),
				reference("DEFINITION")
			}),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal(","),
					repetition(
						reference("IC")
					),
					reference("TYPE_CONSTRAINT_CHAIN")
				})
			)
		})),
production("TYPE_CONSTRAINT_HEAD", sequence({
			optional(
				sequence({
					reference("XML_DOC_STRING", "XML_DOC_STRING"),
					repetition(
						reference("IC")
					)
				})
			),
			repetition(
				sequence({
					reference("ATTRIBUTE"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				sequence({
					reference("VISIBILITY_MODIFIER", "VISIBILITY_MODIFIER"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				sequence({
					literal("static", "static"),
					repetition(
						reference("IC")
					)
				})
			),
			optional(
				sequence({
					literal("extern", "extern"),
					repetition(
						reference("IC")
					)
				})
			),
			choice("type_dereference", {
				reference("TYPE_DEREFERENCE"),
				reference("VOLATILE_TYPE_DEREFERENCE"),
				reference("IMPLICIT_TYPE_DEREFERENCE"),
				reference("VOLATILE_IMPLICIT_TYPE_DEREFERENCE")
			})
		})),
production("TYPE_DEREFERENCE", sequence({
			literal("<"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(">")
		})),
production("TYPE_INVOCATION", sequence({
			reference("EXPRESSION"),
			sequence({
				literal("<"),
				optional(
					sequence({
						repetition(
							reference("IC")
						),
						choice({
							reference("ARGUMENT"),
							reference("ARGUMENT_PACK")
						})
					})
				),
				repetition(
					sequence({
						repetition(
							reference("IC")
						),
						literal(","),
						optional(
							sequence({
								repetition(
									reference("IC")
								),
								choice({
									reference("ARGUMENT"),
									reference("ARGUMENT_PACK")
								})
							})
						)
					})
				),
				repetition(
					reference("IC")
				),
				literal(">")
			})
		})),
production("TYPE_SCOPE", sequence({
			repetition(
				reference("IC")
			),
			repetition(
				sequence({
					reference("TYPE_STATEMENT"),
					repetition(
						reference("IC")
					)
				})
			)
		})),
production("TYPE_SCOPE_ASSIGNMENT_CHAIN", sequence({
			optional(
				sequence({
					reference("XML_DOC_STRING"),
					repetition(
						reference("IC")
					)
				})
			),
			reference("IDENTIFIER"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("MEMBER_OFFSET")
				})
			),
			repetition(
				reference("IC")
			),
			choice({
				literal("←"),
				literal("<-")
			}),
			repetition(
				reference("IC")
			),
			choice({
				reference("EXPRESSION"),
				reference("ASSIGNMENT_CHAIN")
			})
		}),
		associativity::none, filter_function(), {"EXPRESSION", }),
production("TYPE_SCOPE_DECLARATION", sequence({
			optional(
				sequence({
					reference("XML_DOC_STRING"),
					repetition(
						reference("IC")
					)
				})
			),
			reference("IDENTIFIER"),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					reference("MEMBER_OFFSET")
				})
			)
		})),
production("TYPE_SCOPE_TYPE_CONSTRAINT", sequence({
			reference("TYPE_CONSTRAINT_HEAD"),
			repetition(
				reference("IC")
			),
			reference("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN")
		}),
		associativity::none, filter_function(), {"TYPE_CONSTRAINT", }),
production("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN", sequence({
			optional(
				sequence({
					reference("XML_DOC_STRING"),
					repetition(
						reference("IC")
					)
				})
			),
			choice({
				reference("TYPE_SCOPE_DECLARATION"),
				reference("TYPE_SCOPE_ASSIGNMENT_CHAIN"),
				reference("DEFINITION")
			}),
			optional(
				sequence({
					repetition(
						reference("IC")
					),
					literal(","),
					repetition(
						reference("IC")
					),
					reference("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN")
				})
			)
		})),
production("TYPE_STATEMENT", choice({
			sequence({
				reference("VISIBILITY_MODIFIER"),
				repetition(
					reference("IC")
				),
				literal(":")
			}),
			reference("TYPE_SCOPE_TYPE_CONSTRAINT"),
			reference("STATEMENT")
		})),
production("UNARY_ARITHMETIC_OP", choice({
			reference("FACTORIAL"),
			reference("NEGATION"),
			reference("POST_DEC"),
			reference("POST_INC"),
			reference("PRE_DEC"),
			reference("PRE_INC"),
			reference("RADICAL")
		})),
production("UNARY_LOGICAL_OP", choice({
			reference("ALL"),
			reference("EXISTS"),
			reference("EXISTS_ONE"),
			reference("NOT")
		}),
		associativity::none, filter_function(), {"BINARY_LOGICAL_OP", }),
production("UNARY_OP", choice({
			reference("ALLOCATION"),
			reference("CARDINALITY"),
			reference("KLEENE_STAR"),
			reference("UNARY_ARITHMETIC_OP"),
			reference("UNARY_LOGICAL_OP")
		})),
production("UNION", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("∪"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::any),
production("UNIT_DIVISION", sequence({
			reference("DIMENSION"),
			literal("/"),
			reference("DIMENSION")
		}),
		associativity::left),
production("UNIT_EXPONENTIATION", sequence({
			reference("DIMENSION"),
			literal("^"),
			reference("NON_FRACTIONAL")
		}),
		associativity::right, filter_function(), {"UNIT_DIVISION", "UNIT_MULTIPLICATION", }),
production("UNIT_MULTIPLICATION", sequence({
			reference("DIMENSION"),
			literal("*"),
			reference("DIMENSION")
		}),
		associativity::left),
production("UPCASTS", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("upcasts"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("USING", sequence({
			literal("using"),
			repetition(
				reference("IC")
			),
			literal("("),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(")"),
			repetition(
				reference("IC")
			),
			reference("BLOCK")
		})),
production("VECTOR_NORM", sequence({
			literal("||"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal("||")
		})),
production("VISIBILITY_MODIFIER", choice({
			literal("public"),
			literal("protected"),
			literal("protected internal"),
			literal("internal"),
			literal("private")
		})),
production("VOLATILE_IMPLICIT_TYPE_DEREFERENCE", sequence({
			literal("<"),
			repetition(
				reference("IC")
			),
			literal("volatile"),
			repetition(
				reference("IC")
			),
			literal(">")
		})),
production("VOLATILE_TYPE_DEREFERENCE", sequence({
			literal("<"),
			repetition(
				reference("IC")
			),
			literal("volatile"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			literal(">")
		})),
production("WHOLE_NUMBER", sequence({
			choice({
				literal("1"),
				literal("2"),
				literal("3"),
				literal("4"),
				literal("5"),
				literal("6"),
				literal("7"),
				literal("8"),
				literal("9")
			}),
			repetition(
				choice({
					literal("0"),
					literal("1"),
					literal("2"),
					literal("3"),
					literal("4"),
					literal("5"),
					literal("6"),
					literal("7"),
					literal("8"),
					literal("9")
				})
			)
		})),
production("WRITE_LOCK", sequence({
			literal("write_lock"),
			repetition(
				reference("IC")
			),
			reference("PARENTHETICAL"),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		})),
production("WS", sequence({
			reference("white_space"),
			repetition(
				reference("white_space")
			)
		}),
		associativity::none, builtins.longest),
production("XML_DOC_STRING", sequence({
			literal("```"),
			reference("XML_DOC_STRING_INTERIOR"),
			literal("```")
		})),
production("XML_DOC_STRING_INTERIOR", choice({
			reference("PAYLOAD"),
			sequence({
				literal("`"),
				reference("XML_DOC_STRING_INTERIOR"),
				literal("`")
			})
		})),
production("XOR", sequence({
			reference("EXPRESSION"),
			repetition(
				reference("IC")
			),
			choice({
				literal("⊕"),
				literal("xor")
			}),
			repetition(
				reference("IC")
			),
			reference("EXPRESSION")
		}),
		associativity::left),
});