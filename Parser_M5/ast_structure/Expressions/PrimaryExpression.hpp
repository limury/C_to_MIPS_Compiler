
#ifndef PRIMARYEXPRESSION
#define PRIMARYEXPRESSION

#include "../structures.hpp"

#include <string>
#include <iostream>


class PrimaryExpression : public ConstExpression{
  public:
    enum PrimaryExpressionType { IDENTIFIER, LIT_CHAR, LIT_STRING, LIT_DOUBLE, LIT_INT, EXPR };

  private:
    PrimaryExpression ( const std::string& attribute );
    PrimaryExpression ( const int& attribute );
    PrimaryExpression ( const double& attribute );
    PrimaryExpression ( ExpressionPtr attribute );
    PrimaryExpression ( const char& attribute );

    std::string str;
    int integer;
    double decimal;
    ExpressionPtr expression;
    char character;
    PrimaryExpressionType expressionType;

};

#endif