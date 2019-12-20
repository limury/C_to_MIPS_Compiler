
#ifndef TERMEXPRESSION
#define TERMEXPRESSION

#include "../structures.hpp"

class TermExpression : public ConstExpression{
  public:
    enum TermOperator { PLUS = 0, MINUS = 1 };
    TermExpression ( TermExpressionPtr termExpr, FactorExpressionPtr factorExpr, int n );
  private:
    TermExpressionPtr termExpression;
    FactorExpressionPtr factorExpression;

    TermOperator op;
    
};

#endif