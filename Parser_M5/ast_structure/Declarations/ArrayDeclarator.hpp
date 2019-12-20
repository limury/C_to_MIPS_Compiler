#ifndef ARRAYDECLARATOR
#define ARRAYDECLARATOR

#include "../structures.hpp"

class ArrayDeclarator: public DirectDeclarator {
  public:
    ArrayDeclarator(DirectDeclaratorPtr dir_decl, ConstExpressionPtr n);

  private:
    DirectDeclaratorPtr direct_declarator;
    ConstExpressionPtr size;
};


#endif