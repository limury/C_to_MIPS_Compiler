
#ifndef BITOREXPRESSION
#define BITOREXPRESSION

#include "../structures.hpp"

class BitOrExpression : public ConstExpression{
  public:
    BitOrExpression (BitOrExpressionPtr bitOrExpr, BitXorExpressionPtr bitXorExpr);
  private:
    BitOrExpressionPtr bitOrExpression;
    BitXorExpressionPtr bitXorExpression;
};

#endif