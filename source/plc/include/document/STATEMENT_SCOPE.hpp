// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATEMENT_SCOPE_HPP
#define INCLUDED_STATEMENT_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct STATEMENT;

typedef std::vector<std::variant<
	erased<IC>,
	erased<STATEMENT>
>> STATEMENT_SCOPE_base;

struct STATEMENT_SCOPE: STATEMENT_SCOPE_base {
	static std::optional<STATEMENT_SCOPE> build(std::vector<parlex::details::match>::iterator & i);
	explicit STATEMENT_SCOPE(STATEMENT_SCOPE_base const & value) : STATEMENT_SCOPE_base(value) {}
};
} // namespace plc



#endif //INCLUDED_STATEMENT_SCOPE_HPP