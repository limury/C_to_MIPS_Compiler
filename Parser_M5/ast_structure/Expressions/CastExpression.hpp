
#ifndef CASTEXPRESSION
#define CASTEXPRESSION

#include "../structures.hpp"

class CastExpression : public ConstExpression{
  public:
    CastExpression ( TypeNamePtr typeNm, CastExpressionPtr castExpr );
  private:
    TypeNamePtr typeName;
    CastExpressionPtr castExpression;

};

#endif