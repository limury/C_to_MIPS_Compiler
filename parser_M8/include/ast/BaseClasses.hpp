#ifndef ROOT
#define ROOT
#include "../includes.hpp"

// Every other class is just an implementation of this. This is just for ease in the parser type definitions.
class Root {
  public:
    virtual string printAST(){}
    virtual void getMIPS(vector<Instruction>& instruction, Context& context, int destreg = 0) {}
    virtual void append(RootPtr element){}
};
typedef const Root* RootPtr;

class RootExpression : public Root {

};


#endif