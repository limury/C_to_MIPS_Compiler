#include "../ast_structure/Expressions/BitXorExpression.hpp"


BitXorExpression::BitXorExpression (BitXorExpressionPtr bitXorExpr, BitAndExpressionPtr bitAndExpr)
    :   bitXorExpression(bitXorExpr), bitAndExpression(bitAndExpr){}
