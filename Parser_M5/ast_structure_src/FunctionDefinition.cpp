
#include "../ast_structure/Declarators/FunctionDefinition.hpp"



FunctionDefinition::FunctionDefinition( FullTypePtr fullTp, Declarator decl, CompoundStatementPtr compoundStmt )
    :   fullType(fullTp), declarator(decl), compoundStatement(compoundStmt){}
