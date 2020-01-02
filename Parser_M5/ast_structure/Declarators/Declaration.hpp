#ifndef DECLARATION
#define DECLARATION

#include "../structures.hpp"


class FunctionDefinition : public TranslationUnit{
  public:
    FunctionDefinition( FullTypePtr fullTp, Declarator decl, CompoundStatementPtr compoundStmt );

  private:
    FullTypePtr fullType;
    Declarator declarator;
    CompoundStatementPtr compoundStatement;
};


#endif