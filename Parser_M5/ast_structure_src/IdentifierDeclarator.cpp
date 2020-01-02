
#include "../ast_structure/Declarators/IdentifierDeclarator.hpp"


IdentifierDeclarator::IdentifierDeclarator(std::string id): identifier(id){
    DirectDeclarator::declarator_type = _identifier;
}

