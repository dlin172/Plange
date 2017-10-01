// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RELATIONAL_COLLECTION_OP_HPP
#define INCLUDED_RELATIONAL_COLLECTION_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct HAS;
struct IN;
struct NOT_HAS;
struct NOT_IN;

typedef std::variant<
	erased<HAS>,
	erased<IN>,
	erased<NOT_HAS>,
	erased<NOT_IN>
> RELATIONAL_COLLECTION_OP_base;

struct RELATIONAL_COLLECTION_OP: RELATIONAL_COLLECTION_OP_base {
	static std::optional<RELATIONAL_COLLECTION_OP> build(std::vector<parlex::details::match>::iterator & i);
	explicit RELATIONAL_COLLECTION_OP(RELATIONAL_COLLECTION_OP_base const & value) : RELATIONAL_COLLECTION_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_RELATIONAL_COLLECTION_OP_HPP