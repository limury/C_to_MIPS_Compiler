#ifndef DECLARATION
#define DECLARATION

#include "../structures.hpp"

class Declaration {
  public:
    Declaration(FullTypePtr type, InitDeclaratorListPtr list);
    
  private:
    FullTypePtr fullType;
    InitDeclaratorListPtr declList;
    
};

#endif