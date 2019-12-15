#ifndef FUNCTION
#define FUNCTION

#include "../structures.hpp"

class Function {

  public:
    Function(const FullType* type, const Declarator* decl, const CompoundStatement* expr);

  private:
    FullType* type_specifics;
    Declarator* declarator;
    CompoundStatement* expr;


};

#endif