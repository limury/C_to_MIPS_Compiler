
#include "../ast_structure/Declarations/FunctionDefinition.hpp"



FunctionDeclarator::FunctionDeclarator(DirectDeclaratorPtr dir_decl, std::vector<VariablePtr> param_list): direct_declarator(dir_decl), param_type_list(param_list){
    DirectDeclarator::declarator_type = _function;
}
