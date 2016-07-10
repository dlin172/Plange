#ifndef INTEGER_DIVISION_EXP_H
#define INTEGER_DIVISION_EXP_H

#include "BinaryOpExp.h"
class IntegerDivisionExp :
	public BinaryOpExp
{
public:
	IntegerDivisionExp();
	~IntegerDivisionExp();

	std::u32string get_name() const override;

};

#endif //INTEGER_DIVISION_EXP_H
