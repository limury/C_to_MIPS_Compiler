
#ifndef EQUALITYEXPRESSION
#define EQUALITYEXPRESSION

#include "../structures.hpp"

class EqualityExpression : public ConstExpression{
  public:
    enum EqualityOperator { NE = 0, EQ = 1 };
    EqualityExpression (EqualityExpressionPtr equalityExpr, RelationalExpressionPtr relationalExpr, int n);
  private:
    EqualityExpressionPtr equalityExpression;
    RelationalExpressionPtr relationalExpression;
    EqualityOperator op;
    
};

#endif