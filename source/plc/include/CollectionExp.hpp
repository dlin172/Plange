#ifndef COLLECTION_EXP_HPP
#define COLLECTION_EXP_HPP

#include "Expression.hpp"
#include <vector>
#include <memory>

class CollectionExp :
	public Expression {
public:
	CollectionExp();
	CollectionExp(CollectionExp const & other);
	~CollectionExp() = default;
	std::vector<std::unique_ptr<Expression>> elements;
	virtual value evaluate(execution_context &exc) const = 0;
};

#endif //COLLECTION_EXP_HPP