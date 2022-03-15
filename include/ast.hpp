#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "RegisterMaps.hpp"
#include "PyContext.hpp"
#include "CompContext.hpp"
#include "ast/ast_root.hpp"
#include "ast/ast_base_classes.hpp"
#include "ast/ast_expressions.hpp"
#include "ast/ast_declarations.hpp"
#include "ast/ast_statements.hpp"
#include "ast/ast_top.hpp"

extern AST* parseAST();
extern AST* parseAST(char* in);

#endif