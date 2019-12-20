
#include "../ast_structure/Expressions/OrExpression.hpp"

OrExpression::OrExpression (OrExpressionPtr orExpr, AndExpressionPtr andExpr): orExpression(orExpr), andExpression(andExpr){}
