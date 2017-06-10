#ifndef ANY_CHARACTER_HPP
#define ANY_CHARACTER_HPP

#include "terminal.hpp"

namespace parlex {
namespace details {

class any_character_t : public terminal {
public:
	any_character_t();
	virtual ~any_character_t() = default;
	bool test(std::u32string const & document, size_t documentPosition) const override final;
};

} // namespace details
} // namespace parlex

#endif
