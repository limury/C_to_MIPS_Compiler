#ifndef FUNCTION
#define FUNCTION

#include "../structures.hpp"

class Function {

  public:
    Function();
  private:
    Fulltype type_specifics;
    Declarator declarator;
    DeclaratorList decl_list;
    Compound_Statement expr;


};

#endif