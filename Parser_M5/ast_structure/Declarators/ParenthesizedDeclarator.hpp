#ifndef PARENTHESIZEDDECLARATOR
#define PARENTHESIZEDDECLARATOR

#include "../structures.hpp"

class ParenthesizedDeclarator: public DirectDeclarator {
  public:
    ParenthesizedDeclarator(DeclaratorPtr decl);

  private:
    DeclaratorPtr declarator;
};


#endif