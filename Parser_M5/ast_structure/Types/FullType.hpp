#ifndef FULLTYPE
#define FULLTYPE

#include "../structures.hpp"



class FullType {
  public:
    enum StorageClassSpecifer { TYPEDEF, EXTERN, STATIC, AUTO, REGISTER };
    enum TypeQualifier { CONST, VOLATILE };
    
    FullType (StorageClassSpecifer str, TypeQualifier tpql, TypeSpecifierPtr tpsp);

  private:
    StorageClassSpecifer classSpecifier;
    TypeQualifier typeQualifier;
    TypeSpecifierPtr typeSpecifier;

};

#endif