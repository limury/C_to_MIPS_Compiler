#ifndef EXPRESSIONS
#define EXPRESSIONS
#include "../includes.hpp"
#include "BaseClasses.hpp"

enum primaryExprEnum { IDENTIFIER, CONSTANT, STRING_LIT };
class PrimaryExpression : public Root {
    public:
    PrimaryExpression(primaryExprEnum type, const string* name): _type(type), _value(name) {}

    protected:
    primaryExprEnum _type;
    string _value;
};


// Postfix

class ArrayPostfixExpression : public Root {
    public:
    ArrayPostfixExpression(RootPtr postExpr, RootPtr expr): _postfixExpression(postExpr), _expr(expr) {}

    protected:
    RootPtr _postfixExpression, _expr;
};

class FunctionPostfixExpression : public Root {
    public:
    FunctionPostfixExpression(RootPtr postExpr, RootPtr expr): _postfixExpression(postExpr), _argumentExpressionList(expr) {}

    protected:
    RootPtr _postfixExpression, _argumentExpressionList;
};

class DotPostfixExpression : public Root {
    public:
    DotPostfixExpression(RootPtr postExpr, const string& expr): _postfixExpression(postExpr), _identifier(expr) {}

    protected:
    RootPtr _postfixExpression, _identifier;
};

class ArrowPostfixExpression : public Root {
    public:
    ArrowPostfixExpression(RootPtr postExpr, const string& expr): _postfixExpression(postExpr), _identifier(expr) {}

    protected:
    RootPtr _postfixExpression, _identifier;
};
class IncrementPostfixExpression : public Root {
    public:
    IncrementPostfixExpression(RootPtr postExpr): _postfixExpression(postExpr) {}

    protected:
    RootPtr _postfixExpression;
};
class DecrementPostfixExpression : public Root {
    public:
    DecrementPostfixExpression(RootPtr postExpr): _postfixExpression(postExpr) {}

    protected:
    RootPtr _postfixExpression;
};


// Unary
class PreincrementUnaryExpression : public Root {
    public:
    PreincrementUnaryExpression(RootPtr postExpr): _unaryExpression(postExpr) {}

    protected:
    RootPtr _unaryExpression;
};
class PredecrementUnaryExpression : public Root {
    public:
    PredecrementUnaryExpression(RootPtr postExpr): _unaryExpression(postExpr) {}

    protected:
    RootPtr _unaryExpression;
};

class SizeofUnaryExpression : public Root {
    public:
    SizeofUnaryExpressions(RootPtr postExpr): _unaryExpression(postExpr) {}

    protected:
    RootPtr _unaryExpression;
};
class SizeofTypeUnaryExpression : public Root {
    public:
    SizeofTypeUnaryExpression(RootPtr postExpr): _unaryExpression(postExpr) {}

    protected:
    RootPtr _typeName;
};

enum unaryOperator { REFERENCE, DEREFERENCE, MINUS, BITWISE_NOT, LOGICAL_NOT };

class UnaryOperatorExpression : public Root {
    public:
    UnaryOperatorExpression(unaryOperator op, RootPtr expr): _operator(op), _unaryExpression(expr) {}

    protected:
    unaryOperator _operator;
    RootPtr _unaryExpression;
};



// Multiplicative

class MultiplicationExpression : public Root {
    public:
    MultiplicativeExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class DivisionExpression : public Root {
    public:
    DivisionExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class ModulusExpression : public Root {
    public:
    ModulusExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};

class AdditionExpression : public Root {
    public:
    AdditionExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class SubtractionExpression : public Root {
    public:
    SubtractionExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};

class LeftShiftExpression : public Root {
    public:
    LeftShiftExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class RightShiftExpression : public Root {
    public:
    RightShiftExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};


class LessThanExpression : public Root {
    public:
    LessThanExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class GreaterThanExpression : public Root {
    public:
    GreaterThanExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class LessEqualExpression : public Root {
    public:
    LessEqualExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class GreaterEqualExpression : public Root {
    public:
    GreaterEqualExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};

class EqualityExpression : public Root {
    public:
    EqualityExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class InequalityExpression : public Root {
    public:
    InequalityExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};

class AndBitwiseExpression : public Root {
    public:
    AndBitwiseExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class XorBitwiseExpression : public Root {
    public:
    XorBitwiseExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class OrBitwiseExpression : public Root {
    public:
    OrBitwiseExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};

class OrLogicalExpression : public Root {
    public:
    OrLogicalExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class AndLogicalExpression : public Root {
    public:
    AndLogicalExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};

// Conditional Expression

class ConditionalExpression : public Root {
    public:
    ConditionalExpression(RootPtr condition, RootPtr iftrueExpr, RootPtr iffalseExpr): _condition(condition), _ifTrueExpression(iftrueExpr), _ifFalseExpression(iffalseExpr) {}

    protected:
    RootPtr _condition, _ifTrueExpression, _ifFalseExpression;
};


class EqualAssignmentExpression : public Root {
    public:
    EqualAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class MultAssignmentExpression : public Root {
    public:
    MultAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class DivAssignmentExpression : public Root {
    public:
    DivAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class ModAssignmentExpression : public Root {
    public:
    ModAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class AddAssignmentExpression : public Root {
    public:
    AddAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class SubAssignmentExpression : public Root {
    public:
    SubAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class LeftAssignmentExpression : public Root {
    public:
    LeftAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class RightAssignmentExpression : public Root {
    public:
    RightAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class AndAssignmentExpression : public Root {
    public:
    AndAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class XorAssignmentExpression : public Root {
    public:
    XorAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};
class OrAssignmentExpression : public Root {
    public:
    OrAssignmentExpression (RootPtr var1, RootPtr var2): _var1(var1), _var2(var2) {}

    protected:
    RootPtr _var1, _var2;
};


// Expression which is just an expression list
class ExpressionList : public Root {
  public:
    ExpressionList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }
    ExpressionList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }
    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};

class ArgumentExpressionList : public Root {
  public:
    ArgumentExpressionList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }
    ArgumentExpressionList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }
    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};

#endif