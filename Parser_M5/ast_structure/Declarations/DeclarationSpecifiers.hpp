#ifndef DECLARATIONSPECIFIERS
#define DECLARATIONSPECIFIERS

#include "../structures.hpp"

enum StorageClassSpecifier { TYPEDEF, EXTERN, STATIC, AUTO, REGISTER };

class DeclarationSpecifiers {
  public:

    enum DeclarationSpecifierType { STORAGE_TYPE, TYPE_SPECIFIER, TYPE_QUALIFIER };

    DeclarationSpecifiers(FullTypePtr type, InitDeclaratorListPtr list);
    
  private:
    FullTypePtr fullType;
    InitDeclaratorListPtr declList;
    
};

#endif