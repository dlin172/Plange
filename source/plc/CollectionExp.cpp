
#include "CollectionExp.h"

CollectionExp::CollectionExp()
{

}

CollectionExp::CollectionExp(CollectionExp const & other)
{
	for (auto const & element : other.elements) {
		elements.resize(elements.size() + 1);
		auto temp = clone(*element);
		elements.rbegin()->swap(temp);
	}
}

