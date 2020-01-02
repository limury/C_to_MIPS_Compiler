
#include "../ast_structure/Expressions/UnaryExpression.hpp"

UnaryExpression::UnaryExpression ( int pre, UnaryExpressionPtr unaryExpr )
    :   preOperator(PreOperator(pre)), unaryExpression(unaryExpr){
        if ( preOperator == PLUS_PLUS ) { unaryExpressionType = pre_increment; }
        else if ( preOperator == MINUS_MINUS ) { unaryExpressionType = pre_decrement; }
        else { unaryExpressionType = pre_sizeof; }
    }

UnaryExpression::UnaryExpression ( int pre, TypeNamePtr tpNm )
    :   preOperator(PreOperator(pre)), typeName(tpNm){
        unaryExpressionType = pre_sizeof_parenthesis;
    }
UnaryExpression::UnaryExpression ( UnaryOperator unaryOp, CastExpressionPtr castExpr )
    :   unaryOperator(unaryOp), castExpression(castExpr) {
        unaryExpressionType = unary_op;
    }
