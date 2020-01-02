
#ifndef POSTFIXEXPRESSION
#define POSTFIXEXPRESSION

#include "../structures.hpp"



class PostfixExpression : public ConstExpression{
  public:
    enum PostfixExpressionOperator { DOT, ARROW, PLUS_PLUS, MINUS_MINUS };
    enum PostfixExpressionType { ARRAY_ADDRESSING, FUNCTION_CALL_NO_PARAMETERS, FUNCTION_CALL,
                             STRUCT_ATTRIBUTE_ADDRESSING, STRUCT_PTR_ATTRIBUTE_ADDRESSING,
                             PLUS_PLUS, MINUS_MINUS };
    
    PostfixExpression ( PostfixExpressionPtr postfixExpr, ExpressionPtr expr );
    PostfixExpression ( PostfixExpressionPtr postfixExpr );
    PostfixExpression ( PostfixExpressionPtr postfixExpr, ArgumentExpressionListPtr argumentExprList );
    PostfixExpression ( PostfixExpressionPtr postfixExpr, PostfixExpressionOperator postfixExprOperator, IdentifierPtr ident );
    PostfixExpression ( PostfixExpressionPtr postfixExpr, PostfixExpressionOperator postfixExprOperator );


  private:
    PostfixExpressionPtr postfixExpression;
    ExpressionPtr expression;
    ArgumentExpressionListPtr argumentExpressionList;
    IdentifierPtr identifier;

    PostfixExpressionOperator postfixExpressionOperator;
    PostfixExpressionType postfixExpressionType;
};

#endif