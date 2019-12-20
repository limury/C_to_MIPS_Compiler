#include "../ast_structure/Expressions/BitAndExpression.hpp"


BitAndExpression::BitAndExpression (BitAndExpressionPtr bitAndExpr, EqualityExpressionPtr equalityExpr)
    :   bitAndExpression(bitAndExpr), equalityExpression(equalityExpr){}
