// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_NON_FRACTIONAL_HPP
#define INCLUDED_NON_NEG_NON_FRACTIONAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct HEX;
struct NON_NEG_INTEGER;
struct OCTAL;

typedef std::variant<
	erased<NON_NEG_INTEGER>,
	erased<HEX>,
	erased<OCTAL>
> NON_NEG_NON_FRACTIONAL_base;

struct NON_NEG_NON_FRACTIONAL: NON_NEG_NON_FRACTIONAL_base {
	static std::optional<NON_NEG_NON_FRACTIONAL> build(std::vector<parlex::details::match>::iterator & i);
	explicit NON_NEG_NON_FRACTIONAL(NON_NEG_NON_FRACTIONAL_base const & value) : NON_NEG_NON_FRACTIONAL_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NON_NEG_NON_FRACTIONAL_HPP
