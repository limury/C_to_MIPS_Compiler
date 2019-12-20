
#ifndef BITANDEXPRESSION
#define BITANDEXPRESSION

#include "../structures.hpp"

class BitAndExpression : public ConstExpression{
  public:
    BitAndExpression (BitAndExpressionPtr bitAndExpr, EqualityExpressionPtr equalityExpr);

  private:
    BitAndExpressionPtr bitAndExpression;
    EqualityExpressionPtr equalityExpression;

};

#endif