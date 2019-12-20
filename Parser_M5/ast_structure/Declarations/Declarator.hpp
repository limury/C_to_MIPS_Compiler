#ifndef DECLARATOR
#define DECLARATOR

#include "../structures.hpp"

class DirectDeclarator;

class Declarator {
  public:
    Declarator(int n, DirectDeclarator dir_decl);

  private:
    int num_of_pointers;
    DirectDeclaratorPtr direct_declarator;

};

class DirectDeclarator {
  public:
    enum DirectDeclaratorType { _identifier, _parenthesized_declarator, _array, _array_size, _function };
  protected:
    DirectDeclaratorType declarator_type;
};

#endif