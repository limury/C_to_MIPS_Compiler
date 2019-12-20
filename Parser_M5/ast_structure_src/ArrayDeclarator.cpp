
#include "../ast_structure/Declarations/ArrayDeclarator.hpp"


ArrayDeclarator::ArrayDeclarator(DirectDeclaratorPtr dir_decl, ConstExpressionPtr n): direct_declarator(dir_decl), size(n){
    if (!n){
        DirectDeclarator::declarator_type = _array;
    }
    else {
        DirectDeclarator::declarator_type = _array_size;
    }
}

