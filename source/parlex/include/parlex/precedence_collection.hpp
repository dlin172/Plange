#ifndef PRECEDENCE_COLLECTION_HPP
#define PRECEDENCE_COLLECTION_HPP

#include <coherent_set.hpp>

namespace parlex {
namespace detail {

typedef std::vector<collections::coherent_set<size_t>> precedence_collection;

}
} // namespace parlex

#endif //PRECEDENCE_COLLECTION_HPP
