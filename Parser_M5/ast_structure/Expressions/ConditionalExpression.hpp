
#ifndef CONDITIONALEXPRESSION
#define CONDITIONALEXPRESSION

#include "../structures.hpp"

class ConditionalExpression : public ConstExpression{
  public:
    ConditionalExpression (OrExpressionPtr lorExpr, ExpressionPtr expr, ConditionalExpressionPtr condExpr);
  private:
    OrExpressionPtr orExpression;
    ExpressionPtr expression;
    ConditionalExpressionPtr condExpression;
};

#endif