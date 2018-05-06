#include "parlex/detail/configuration.hpp"

#include "utils.hpp"

namespace parlex {
namespace detail {

configuration::configuration(configuration const* const prior, uint32_t const documentPosition, std::optional<match> const & fromTransition, leaf const * l) :
	prior(prior),
	current_document_position(documentPosition),
	from_transition(fromTransition),
	l(l) {
	throw_assert((prior != nullptr) == fromTransition.has_value());
	//DBG("constructed configuration ", target);
}

configuration::~configuration() {
	//DBG("destructed configuration ", name);
}

derivation configuration::result() const {
	derivation result;
	auto current = this;
	while (current->prior) {
		result.emplace_back(match(*current->from_transition), current->l);
		current = current->prior;
	}
	// std::reverse would require a swap function to be defined for match
	return derivation(result.rbegin(), result.rend());
}

}
}
