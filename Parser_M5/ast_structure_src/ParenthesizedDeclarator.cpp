#include "../ast_structure/Declarators/ParenthesizedDeclarator.hpp"

ParenthesizedDeclarator::ParenthesizedDeclarator(DeclaratorPtr decl): declarator(decl){
    DirectDeclarator::declarator_type = _parenthesized_declarator;
}
