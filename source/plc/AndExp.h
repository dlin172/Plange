#ifndef AND_EXP_H
#define AND_EXP_H

#include "BinaryOpExp.h"
class AndExp :
	public BinaryOpExp
{
public:
	AndExp();
	~AndExp();

	std::u32string get_name() const override;

};

#endif //AND_EXP_H
