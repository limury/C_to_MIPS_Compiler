
#include "../ast_structure/Expressions/AndExpression.hpp"


AndExpression::AndExpression (AndExpressionPtr andExpr, BitOrExpressionPtr bitOrExpr)
    :   andExpression(andExpr), bitOrExpression(bitOrExpr){}
