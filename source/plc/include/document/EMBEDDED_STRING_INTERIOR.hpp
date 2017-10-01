// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_STRING_INTERIOR_HPP
#define INCLUDED_EMBEDDED_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EMBEDDED_STRING_INTERIOR;
struct PAYLOAD;

typedef std::variant<
	erased<PAYLOAD>,
	std::tuple<
		erased<EMBEDDED_STRING_INTERIOR>
	>
> EMBEDDED_STRING_INTERIOR_base;

struct EMBEDDED_STRING_INTERIOR: EMBEDDED_STRING_INTERIOR_base {
	static std::optional<EMBEDDED_STRING_INTERIOR> build(std::vector<parlex::details::match>::iterator & i);
	explicit EMBEDDED_STRING_INTERIOR(EMBEDDED_STRING_INTERIOR_base const & value) : EMBEDDED_STRING_INTERIOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_STRING_INTERIOR_HPP