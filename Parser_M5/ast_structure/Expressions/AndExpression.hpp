
#ifndef ANDEXPRESSION
#define ANDEXPRESSION

#include "../structures.hpp"

class AndExpression : public ConstExpression{
  public:
    AndExpression (AndExpressionPtr andExpr, BitOrExpressionPtr bitOrExpr);
  private:
    AndExpressionPtr andExpression;
    BitOrExpressionPtr bitOrExpression;
};

#endif