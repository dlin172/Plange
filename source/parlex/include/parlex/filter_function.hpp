#ifndef FILTER_FUNCTION_HPP
#define FILTER_FUNCTION_HPP

#include <functional>
#include <set>
#include <list>
#include <memory>

#include "parlex/detail/permutation.hpp"

namespace parlex {

//a function that takes a vector of `permutation`s and returns
//the set of indices into the vector that are passed by the filter
//shared_ptr because std::functions have no equality operator
typedef std::shared_ptr<std::function<std::set<int> (std::u32string const & /*document*/, std::list<detail::permutation> const &)>> filter_function;

} // namespace parlex

#endif //FILTER_FUNCTION_HPP
