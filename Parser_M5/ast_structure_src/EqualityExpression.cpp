#include "../ast_structure/Expressions/EqualityExpression.hpp"

EqualityExpression::EqualityExpression (EqualityExpressionPtr equalityExpr, RelationalExpressionPtr relationalExpr, int n)
    :   equalityExpression(equalityExpr), relationalExpression(relationalExpr), op(EqualityOperator(n)){}

