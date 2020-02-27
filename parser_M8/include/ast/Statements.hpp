#ifndef EXPRESSIONS
#define EXPRESSIONS
#include "../includes.hpp"
#include "BaseClasses.hpp"

// Jump Statements

class ContinueJumpStatement : public Root {
    public:
    ContinueJumpStatement(){} 
};
class BreakJumpStatement : public Root {
    public:
    BreakJumpStatement(){} 
};

class ReturnJumpStatement : public Root {
    public:
    ReturnJumpStatement(RootExpr expr): _expression(expr) {} 
    protected:
    RootPtr _expression;
};


// Loops

class ForIterationStatement : public Root {
    public:
    ForIterationStatement(RootPtr p1, RootPtr p2, RootPtr p3, RootPtr p4): _initializer(p1), _condition(p2), _change(p3), _statement(p4) {}

    protected:
    RootPtr _initializer, _condition, _change, _statement;
};

class WhileIterationStatement : public Root {
    public:
    WhileIterationStatement(RootPtr p1, RootPtr p2): _condition(p1), _statement(p2) {}

    protected:
    RootPtr _condition, _statement;
};
class DoWhileIterationStatement : public Root {
    public:
    DoWhileIterationStatement(RootPtr p1, RootPtr p2): _condition(p1), _statement(p2) {}

    protected:
    RootPtr _condition, _statement;
};

// Select Statements

class IfSelectStatement : public Root {
    public:
    IfSelectStatement(RootPtr cond, RootPtr stmt): _condition(cond), _statement(stmt) {}
    
    protected:
    RootPtr _condition, _statement;
};
class IfElseSelectStatement : public Root {
    public:
    IfElseSelectStatement(RootPtr cond, RootPtr stmt1, RootPtr stmt2): _condition(cond), _ifTrueStatement(stmt1), _ifFalseStatement(stmt2) {}
    
    protected:
    RootPtr _condition, _ifTrueStatement, _ifFalseStatement;
};
class SwitchSelectStatement : public Root {
    public:
    SwitchSelectStatement(RootPtr cond, RootPtr stmt): _expression(cond), _statement(stmt) {}
    
    protected:
    RootPtr _expression, _statement;
};

class ExpressionStatement : public Root {
    public:
    ExpressionStatement(RootPtr param): _expression(param) {}

    protected:
    RootPtr _expression;
};

class StatementList : public Root {
  public:
    StatementList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }
    StatementList(RootPtr decl){
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