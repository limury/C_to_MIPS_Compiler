
#ifndef BITOREXPRESSION
#define BITOREXPRESSION

#include "../structures.hpp"

class BitXorExpression : public ConstExpression{
  public:
    BitXorExpression (BitXorExpressionPtr bitXorExpr, BitAndExpressionPtr bitAndExpr);

  private:
    BitXorExpressionPtr bitXorExpression;
    BitAndExpressionPtr bitAndExpression;

};

#endif