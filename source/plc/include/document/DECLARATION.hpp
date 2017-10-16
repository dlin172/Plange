// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DECLARATION_HPP
#define INCLUDED_DECLARATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct DECLARATION {
	struct field_1_t_1_t {
		erased<XML_DOC_STRING> xml_doc_string;
		
		std::vector<erased<IC>> field_1;
		
	
	
		explicit field_1_t_1_t(
			erased<XML_DOC_STRING> && xml_doc_string, std::vector<erased<IC>> && field_1) : xml_doc_string(std::move(xml_doc_string)), field_1(std::move(field_1)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::optional<field_1_t_1_t> field_1;
	
	erased<IDENTIFIER> identifier;
	


	explicit DECLARATION(
		std::optional<field_1_t_1_t> && field_1, erased<IDENTIFIER> && identifier) : field_1(std::move(field_1)), identifier(std::move(identifier)) {}

	DECLARATION(DECLARATION const & other) = default;
	DECLARATION(DECLARATION && move) = default;

	static DECLARATION build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DECLARATION_HPP
