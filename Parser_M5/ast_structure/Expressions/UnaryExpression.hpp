
#ifndef UNARYEXPRESSION
#define UNARYEXPRESSION

#include "../structures.hpp"

enum UnaryExpressionType  { pre_increment, pre_decrement, pre_sizeof_parenthesis, 
                            pre_sizeof, unary_op };

enum UnaryOperator { BIT_AND, MULT, PLUS, MINUS, BIT_NOT, NOT };

class UnaryExpression : public ConstExpression{
  public:
    enum PreOperator { PLUS_PLUS, MINUS_MINUS, SIZEOF };
    UnaryExpression ( int pre, UnaryExpressionPtr unaryExpr );
    UnaryExpression ( int pre, TypeNamePtr tpNm );
    UnaryExpression ( UnaryOperator unaryOp, CastExpressionPtr castExpr );
 
  private:
    UnaryExpressionType unaryExpressionType;
    PreOperator preOperator;
    UnaryExpressionPtr unaryExpression;
    TypeNamePtr typeName;
    UnaryOperator unaryOperator;
    CastExpressionPtr castExpression;



};

#endif