#include "../ast_structure/Declarations/ParenthesizedDeclarator.hpp"

ParenthesizedDeclarator::ParenthesizedDeclarator(DeclaratorPtr decl): declarator(decl){
    DirectDeclarator::declarator_type = _parenthesized_declarator;
}
