#include "../ast_structure/Expressions/PrimaryExpression.hpp"

//enum PrimaryExpressionType { IDENTIFIER, LIT_CHAR, LIT_STRING, LIT_DOUBLE, LIT_INT, EXPR };

PrimaryExpression::PrimaryExpression ( const std::string& attribute )
    :   str(attribute), expressionType(LIT_STRING){}

PrimaryExpression::PrimaryExpression ( const int& attribute )
    :   integer(attribute), expressionType(LIT_INT){}

PrimaryExpression::PrimaryExpression ( const double& attribute )
    :   decimal(attribute), expressionType(LIT_DOUBLE){}

PrimaryExpression::PrimaryExpression ( ExpressionPtr attribute )
    :   expression(attribute), expressionType(EXPR){}

PrimaryExpression::PrimaryExpression ( const char& attribute )
    :   character(attribute), expressionType(LIT_CHAR){}
