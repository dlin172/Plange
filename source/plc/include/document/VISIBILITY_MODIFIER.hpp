// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VISIBILITY_MODIFIER_HPP
#define INCLUDED_VISIBILITY_MODIFIER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

typedef std::variant<
	literal_public_t,
	literal_protected_t,
	literal_protected0x20internal_t,
	literal_internal_t,
	literal_private_t
> VISIBILITY_MODIFIER_base;

struct VISIBILITY_MODIFIER: VISIBILITY_MODIFIER_base {
	static std::optional<VISIBILITY_MODIFIER> build(std::vector<parlex::details::match>::iterator & i);
	explicit VISIBILITY_MODIFIER(VISIBILITY_MODIFIER_base const & value) : VISIBILITY_MODIFIER_base(value) {}
};
} // namespace plc



#endif //INCLUDED_VISIBILITY_MODIFIER_HPP
