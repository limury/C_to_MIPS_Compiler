#ifndef STRUCTURES
#define STRUCTURES

#include "../ast_structure/includes.hpp"
#include "../ast_structure/Node.hpp"
#include "../ast_structure/Declarators/FunctionDefinition.hpp"
#include "../ast_structure/Declarators/Declarator.hpp"
#include "../ast_structure/Declarators/ArrayDeclarator.hpp"
#include "../ast_structure/Declarators/IdentifierDeclarator.hpp"
#include "../ast_structure/Declarators/ParenthesizedDeclarator.hpp"


#include "../ast_structure/Expressions/AndExpression.hpp"
#include "../ast_structure/Expressions/BitAndExpression.hpp"
#include "../ast_structure/Expressions/BitOrExpression.hpp"
#include "../ast_structure/Expressions/BitXorExpression.hpp"
#include "../ast_structure/Expressions/CastExpression.hpp"
#include "../ast_structure/Expressions/ConditionalExpression.hpp"
#include "../ast_structure/Expressions/ConstExpression.hpp"
#include "../ast_structure/Expressions/EqualityExpression.hpp"
#include "../ast_structure/Expressions/FactorExpression.hpp"
#include "../ast_structure/Expressions/OrExpression.hpp"
#include "../ast_structure/Expressions/PostfixExpression.hpp"
#include "../ast_structure/Expressions/PrimaryExpression.hpp"
#include "../ast_structure/Expressions/RelationalExpression.hpp"
#include "../ast_structure/Expressions/ShiftExpression.hpp"
#include "../ast_structure/Expressions/TermExpression.hpp"
#include "../ast_structure/Expressions/UnaryExpression.hpp"

#include "../ast_structure/Interfaces/TranslationUnit.hpp"


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
typedef const UnaryExpression* UnaryExpressionPtr; 
typedef const PostfixExpression* PostfixExpressionPtr; 
typedef const ArgumentExpressionList* ArgumentExpressionListPtr;  //
typedef const Identifier* IdentifierPtr;  //
typedef const FullType* FullTypePtr;  //
typedef FullType DeclarationSpecifiers;  
typedef const CompoundStatement* CompoundStatementPtr;  //
typedef const FunctionDefinition* FunctionDefinitionPtr;  
typedef const TranslationUnit* TranslationUnitPtr;  

typedef const InitDeclaratorList* InitDeclaratorListPtr;  
typedef const TypeSpecifier* TypeSpecifierPtr;  




#endif