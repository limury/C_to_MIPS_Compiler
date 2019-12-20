#include "../ast_structure/Expressions/CastExpression.hpp"

CastExpression::CastExpression ( TypeNamePtr typeNm, CastExpressionPtr castExpr )
    :   typeName(typeNm), castExpression(castExpr){}
