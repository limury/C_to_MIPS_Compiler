#include "../ast_structure/Expressions/RelationalExpression.hpp"
    
RelationalExpression::RelationalExpression (RelationalExpressionPtr relationalExpr, ShiftExpressionPtr shiftExpr, int n)
    :   relationalExpression(relationalExpr), shiftExpression(shiftExpr), op(RelationalOperator(n)){}
