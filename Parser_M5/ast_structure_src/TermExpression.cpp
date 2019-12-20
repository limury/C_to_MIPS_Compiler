#include "../ast_structure/Expressions/TermExpression.hpp"


TermExpression::TermExpression ( TermExpressionPtr termExpr, FactorExpressionPtr factorExpr, int n )
    :   termExpression(termExpr), factorExpression(factorExpr), op(TermOperator(n)){}
