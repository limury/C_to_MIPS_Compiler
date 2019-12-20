
#ifndef SHIFTEXPRESSION
#define SHIFTEXPRESSION

#include "../structures.hpp"

class ShiftExpression : public ConstExpression{
  public:
    enum ShiftOperator { LEFT = 0, RIGHT = 1 };
    ShiftExpression ( ShiftExpressionPtr shiftExpr, TermExpressionPtr termExpr, int n);
  private:
    ShiftExpressionPtr shiftExpression;
    TermExpressionPtr termExpression;

    ShiftOperator op;
    
};

#endif