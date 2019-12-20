#ifndef FUNCTIONDEFINITION
#define FUNCTIONDEFINITION

#include "../structures.hpp"


class FunctionDeclarator: public DirectDeclarator {
  public:
    FunctionDeclarator(DirectDeclaratorPtr dir_decl, std::vector<VariablePtr> param_list);

  private:
    DirectDeclaratorPtr direct_declarator;
    std::vector<VariablePtr> param_type_list;
};


#endif