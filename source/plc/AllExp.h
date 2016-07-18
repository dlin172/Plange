#ifndef ALL_EXP_H
#define ALL_EXP_H

#include "UnaryOpExp.h"
class AllExp :
	public UnaryOpExp
{
public:
	AllExp(Expression const & subExpression);
	~AllExp();
	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //ALL_EXP_H
