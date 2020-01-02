
#include "../ast_structure/Declarations/Declaration.hpp"

Declaration::Declaration(FullTypePtr type, InitDeclaratorListPtr list)
    :   fullType(type), declList(list){}
