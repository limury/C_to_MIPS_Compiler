#ifndef STRUCTURES
#define STRUCTURES

#include "../ast_structure/includes.hpp"
#include "../ast_structure/Node.hpp"
#include "../ast_structure/Declarations/FunctionDefinition.hpp"
#include "../ast_structure/Declarations/Declarator.hpp"
#include "../ast_structure/Declarations/ArrayDeclarator.hpp"
#include "../ast_structure/Declarations/IdentifierDeclarator.hpp"
#include "../ast_structure/Declarations/ParenthesizedDeclarator.hpp"

#include "../ast_structure/Expressions/ConditionalExpression.hpp"
#include "../ast_structure/Expressions/ConstExpression.hpp"




typedef const Declarator* DeclaratorPtr;
typedef const CompStmt* CompStmtPtr; //
typedef const DirectDeclarator* DirectDeclaratorPtr;
typedef const Variable* VariablePtr; //
typedef const ConstExpression* ConstExpressionPtr;
typedef const OrExpression* OrExpressionPtr; //
typedef const AndExpression* AndExpressionPtr; 
typedef const Expression* ExpressionPtr; //
typedef const ConditionalExpression* ConditionalExpressionPtr; 
typedef const BitOrExpression* BitOrExpressionPtr; 
typedef const BitXorExpression* BitXorExpressionPtr; 
typedef const BitAndExpression* BitAndExpressionPtr; 
typedef const EqualityExpression* EqualityExpressionPtr; 
typedef const RelationalExpression* RelationalExpressionPtr; 
typedef const ShiftExpression* ShiftExpressionPtr; 
typedef const TermExpression* TermExpressionPtr; 
typedef const FactorExpression* FactorExpressionPtr; 
typedef const CastExpression* CastExpressionPtr; 
typedef const TypeName* TypeNamePtr; 


#endif