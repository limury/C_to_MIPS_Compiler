
#include "../ast_structure/Expressions/BitOrExpression.hpp"

BitOrExpression::BitOrExpression (BitOrExpressionPtr bitOrExpr, BitXorExpressionPtr bitXorExpr)
    :   bitOrExpression(bitOrExpr), bitXorExpression(bitXorExpr){}
