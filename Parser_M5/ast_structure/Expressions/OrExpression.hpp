
#ifndef OREXPRESSION
#define OREXPRESSION

#include "../structures.hpp"

class OrExpression : public ConstExpression{
  public:
    OrExpression (OrExpressionPtr orExpr, AndExpressionPtr andExpr);
  private:
    OrExpressionPtr orExpression;
    AndExpressionPtr andExpression;
};

#endif