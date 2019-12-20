
#ifndef FACTOREXPRESSION
#define FACTOREXPRESSION

#include "../structures.hpp"

class FactorExpression : public ConstExpression{
  public:
    enum FactorOperator { MUL = 0, DIV = 1, MOD = 2 };
    FactorExpression ( FactorExpressionPtr factorExpr, CastExpressionPtr castExpr, int n );
  private:
    FactorExpressionPtr factorExpression;
    CastExpressionPtr castExpression;

    FactorOperator op;
    
};

#endif