#ifndef INCLUDING_MPL__IF_HPP
#define INCLUDING_MPL__IF_HPP

#include <type_traits>

namespace mpl {
	template<bool Condition, typename TTrue, typename TFalse>
	using _if = typename std::conditional<Condition, TTrue, TFalse>::type;
}

#define INCLUDED_MPL__IF_HPP
#elif !defined(INCLUDED_MPL__IF_HPP)
#	error circular inclusion
#endif