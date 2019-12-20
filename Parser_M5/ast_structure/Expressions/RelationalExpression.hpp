
#ifndef RELATIONALEXPRESSION
#define RELATIONALEXPRESSION

#include "../structures.hpp"

class RelationalExpression : public ConstExpression{
  public:
    enum RelationalOperator { LT = 0, GT = 1, LE = 2, GE = 3};
    RelationalExpression (RelationalExpressionPtr relationalExpr, ShiftExpressionPtr shiftExpr, int n);
  private:
    RelationalExpressionPtr relationalExpression;
    ShiftExpressionPtr shiftExpression;

    RelationalOperator op;
    
};

#endif