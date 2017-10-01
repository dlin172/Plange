// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_COLLECTION_OP_HPP
#define INCLUDED_BINARY_COLLECTION_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct BIJECTION;
struct INTERSECTION;
struct SYMMETRIC_DIFFERENCE;
struct UNION;

typedef std::variant<
	erased<BIJECTION>,
	erased<INTERSECTION>,
	erased<SYMMETRIC_DIFFERENCE>,
	erased<UNION>
> BINARY_COLLECTION_OP_base;

struct BINARY_COLLECTION_OP: BINARY_COLLECTION_OP_base {
	static std::optional<BINARY_COLLECTION_OP> build(std::vector<parlex::details::match>::iterator & i);
	explicit BINARY_COLLECTION_OP(BINARY_COLLECTION_OP_base const & value) : BINARY_COLLECTION_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BINARY_COLLECTION_OP_HPP