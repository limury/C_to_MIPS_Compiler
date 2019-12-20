#include "../ast_structure/Expressions/ShiftExpression.hpp"

ShiftExpression::ShiftExpression ( ShiftExpressionPtr shiftExpr, TermExpressionPtr termExpr, int n)
    :   shiftExpression(shiftExpr), termExpression(termExpr), op(ShiftOperator(n)){}
