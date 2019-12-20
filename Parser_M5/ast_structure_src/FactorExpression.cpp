#include "../ast_structure/Expressions/FactorExpression.hpp"


FactorExpression::FactorExpression ( FactorExpressionPtr factorExpr, CastExpressionPtr castExpr, int n )
    :   factorExpression(factorExpr), castExpression(castExpr), op(FactorOperator(n)){}
