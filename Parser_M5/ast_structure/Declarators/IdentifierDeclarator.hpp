#ifndef IDENTIFIERDECLARATOR
#define IDENTIFIERDECLARATOR

#include "../structures.hpp"

class IdentifierDeclarator: public DirectDeclarator {
  public:
    IdentifierDeclarator(std::string id);

  private:
    std::string identifier;
};


#endif