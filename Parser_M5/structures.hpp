#ifndef STRUCTURES
#define STRUCTURES

#include "ast_structure/includes.hpp"
#include "ast_structure/Node.hpp"
#include "ast_structure/RootNode.hpp"
#include "ast_structure/Function.hpp"
#include "ast_structure/Types.hpp"


typedef const Node* NodePtr;
typedef const RootNode* RootNodePtr;
enum storage_classes { _typedef, _extern, _static, _auto, _register, _default };
enum type_qualifiers { _const, _volatile, _default};
enum default_types { _void, _char, _short, _int, _long, _float, _double, _signed, _unsigned }
std::vector<std::string> structs, enums, unions;


#endif