// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_INTEGER_HPP
#define INCLUDED_NON_NEG_INTEGER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct NON_ZERO_DECIMAL_DIGIT;

typedef std::variant<
	std::tuple<
		erased<NON_ZERO_DECIMAL_DIGIT>,
		int
	>,
	literal_0_t
> NON_NEG_INTEGER_base;

struct NON_NEG_INTEGER: NON_NEG_INTEGER_base {
	static std::optional<NON_NEG_INTEGER> build(std::vector<parlex::details::match>::iterator & i);
	explicit NON_NEG_INTEGER(NON_NEG_INTEGER_base const & value) : NON_NEG_INTEGER_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NON_NEG_INTEGER_HPP
