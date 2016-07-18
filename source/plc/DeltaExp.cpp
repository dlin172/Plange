#include "DeltaExp.h"



DeltaExp::DeltaExp(int const rank, Expression const & subExpression) : rank(rank), sub_expression(clone(subExpression)) {}


DeltaExp::DeltaExp(DeltaExp const & other) : rank(other.rank), sub_expression(clone(*other.sub_expression))
{

}

DeltaExp::~DeltaExp()
{
}
