
#include "../ast_structure/Expressions/ConditionalExpression.hpp"

ConditionalExpression::ConditionalExpression (OrExpressionPtr lorExpr, ExpressionPtr expr, ConditionalExpressionPtr condExpr)
    :   orExpression(lorExpr), expression(expr), condExpression(condExpr){}
