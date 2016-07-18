#ifndef RADICAL_EXP_H
#define RADICAL_EXP_H

#include "UnaryOpExp.h"
#include <memory>

class RadicalExp :
	public UnaryOpExp
{
public:
	RadicalExp(Expression const & subExpression);
	~RadicalExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //RADICAL_EXP_H
