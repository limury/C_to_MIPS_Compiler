%skeleton "skelly.cpp"
%define parser_class_name {Parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define parse.error verbose
%locations

%code requires{
#include "includes.hpp"
#include "skelly.hpp"


struct expr_primary {

}


%}


%token IDENTIFIER LIT_INT LIT_STRING LIT_CHAR LIT_DOUBLE
%token TYPE_CUSTOM TYPE_INT TYPE_DOUBLE TYPE_FLOAT TYPE_STRING TYPE_CHAR TYPE_VOID
%token KEY_AUTO KEY_BREAK KEY_CASE KEY_CONST KEY_CONTINUE KEY_DEFAULT KEY_DO KEY_ELSE
%token KEY_ENUM KEY_EXTERN KEY_FOR KEY_GOTO KEY_IF KEY_LONG KEY_REGISTER KEY_RETURN
%token KEY_SHORT KEY_SIGNED KEY_SIZEOF KEY_STATIC KEY_STRUCT KEY_SWITCH KEY_TYPEDEF
%token KEY_UNION KEY_UNSIGNED KEY_VOLATILE KEY_WHILE

%token OP_PLUS OP_MINUS OP_MULT OP_DIV OP_MODULO OP_LSHIFT OP_RSHIFT
%token OP_LT OP_GT OP_LTEQ OP_GTEQ OP_EQEQ OP_NE OP_BIT_AND OP_AND OP_BIT_OR OP_OR
%token OP_XOR OP_EQ OP_PLUSEQ OP_MINUSEQ OP_MULTEQ OP_DIVEQ OP_MODEQ OP_ANDEQ OP_OREQ OP_XOREQ
%token OP_LSHIFTEQ OP_RSHIFTEQ OP_DOT OP_ARROW OP_COMMA OP_COLON OP_SEMICOLON OP_QUESTION 
%token OP_LPARENTHESES OP_RPARENTHESES OP_LBRACKET OP_RBRACKET OP_LBRACE OP_RBRACE
%token OP_NOT OP_BIT_NOT OP_PLUS_PLUS OP_MINUS_MINUS


%type <expr> expr expr_additive expr_and expr_argument_list expr_assignment expr_bit_and expr_bit_or expr_bit_xor expr_cast expr_unary expr_statement
%type <expr> expr_const expr_equality expr_multiplicative expr_or expr_postfix expr_primary expr_relational expr_shift expr_short_conditional

%type <expr> 

%start translation_unit
%%

expr_primary
	: IDENTIFIER
	| LIT_STRING
	| LIT_STRING
	| OP_LPARENTHESES expr OP_RPARENTHESES
	;

expr_postfix
	: expr_primary
	| expr_postfix OP_LBRACKET expr OP_RBRACKET
	| expr_postfix OP_LPARENTHESES OP_RPARENTHESES
	| expr_postfix OP_LPARENTHESES expr_argument_list OP_RPARENTHESES
	| expr_postfix OP_DOT IDENTIFIER
	| expr_postfix PTR_OP IDENTIFIER
	| expr_postfix INC_OP
	| expr_postfix DEC_OP
	;

expr_argument_list
	: expr_assignment
	| expr_argument_list OP_COMMA expr_assignment
	;

expr_unary
	: expr_postfix
	| INC_OP expr_unary
	| DEC_OP expr_unary
	| op_unary expr_cast
	| SIZEOF expr_unary
	| SIZEOF OP_LPARENTHESES type_name OP_RPARENTHESES
	;

op_unary
	: OP_BIT_AND
	| OP_MULT
	| OP_PLUS
	| OP_MINUS
	| OP_BIT_NOT
	| OP_NOT
	;

expr_cast
	: expr_unary
	| OP_LPARENTHESES type_name OP_RPARENTHESES expr_cast
	;

expr_multiplicative
	: expr_cast
	| expr_multiplicative OP_MULT expr_cast
	| expr_multiplicative OP_DIV expr_cast
	| expr_multiplicative OP_MODULO expr_cast
	;

expr_additive
	: expr_multiplicative
	| expr_additive OP_PLUS expr_multiplicative
	| expr_additive OP_MINUS expr_multiplicative
	;

expr_shift
	: expr_additive
	| expr_shift LEFT_OP expr_additive
	| expr_shift RIGHT_OP expr_additive
	;

expr_relational
	: expr_shift
	| expr_relational OP_LT expr_shift
	| expr_relational OP_GT expr_shift
	| expr_relational OP_LTEQ expr_shift
	| expr_relational OP_GTEQ expr_shift
	;

expr_equality
	: expr_relational
	| expr_equality OP_EQ expr_relational
	| expr_equality OP_NE expr_relational
	;

expr_bit_and
	: expr_equality
	| expr_bit_and OP_BIT_AND expr_equality
	;

expr_bit_xor
	: expr_bit_and
	| expr_bit_xor OP_XOR expr_bit_and
	;

expr_bit_or
	: expr_bit_xor
	| expr_bit_or OP_BIT_OR expr_bit_xor
	;

expr_and
	: expr_bit_or
	| expr_and OP_AND expr_bit_or
	;

expr_or
	: expr_and
	| expr_or OP_OR expr_and
	;

expr_short_conditional
	: expr_or
	| expr_or OP_QUESTION expr OP_COLON expr_short_conditional
	;

expr_assignment
	: expr_short_conditional
	| expr_unary op_assign expr_assignment
	;

op_assign
	: OP_EQ
	| OP_MULTEQ
	| OP_DIVEQ
	| OP_MODEQ
	| OP_PLUSEQ
	| OP_MINUSEQ
	| OP_LSHIFTEQ
	| OP_RSHIFTEQ
	| OP_ANDEQ
	| OP_XOREQ
	| OP_OREQ
	;

expr
	: expr_assignment
	| expr OP_COMMA expr_assignment
	;

expr_const
	: expr_short_conditional
	;

decl
	: decl_specifiers OP_SEMICOLON
	| decl_specifiers declarator_list_init OP_SEMICOLON
	;

decl_specifiers
	: pretype_specifier
	| pretype_specifier decl_specifiers
	| type_specifier
	| type_specifier decl_specifiers
	| qual_type
	| qual_type decl_specifiers
	;

declarator_list_init
	: declarator_init
	| declarator_list_init OP_COMMA declarator_init
	;

declarator_init
	: declarator
	| declarator OP_EQ initializer
	;

pretype_specifier
	: KEY_TYPEDEF
	| KEY_EXTERN
	| KEY_STATIC
	| KEY_AUTO
	| KEY_REGISTER
	;

type_specifier
	: TYPE_VOID
	| TYPE_CHAR
	| KEY_SHORT
	| TYPE_INT
	| KEY_LONG
	| TYPE_FLOAT
	| TYPE_DOUBLE
	| KEY_SIGNED
	| KEY_UNSIGNED
	| customtype_specifier
	| enum_specifier
	| TYPE_CUSTOM
	;

customtype_specifier
	: customtype IDENTIFIER OP_LBRACE decl_list_struct OP_RBRACE
	| customtype OP_LBRACE decl_list_struct OP_RBRACE
	| customtype IDENTIFIER
	;

customtype
	: KEY_STRUCT
	| KEY_UNION
	;

decl_list_struct
	: qual_specifier_list declarator_struct_list OP_SEMICOLON
	| decl_list_struct qual_specifier_list declarator_struct_list OP_SEMICOLON
	;

qual_specifier_list
	: type_specifier qual_specifier_list
	| type_specifier
	| qual_type qual_specifier_list
	| qual_type
	;

declarator_struct_list
	: declarator_struct
	| declarator_struct_list OP_COMMA declarator_struct
	;

declarator_struct
	: declarator
	| OP_COLON expr_const
	| declarator OP_COLON expr_const
	;

enum_specifier
	: ENUM OP_LBRACE enumerator_list OP_RBRACE
	| ENUM IDENTIFIER OP_LBRACE enumerator_list OP_RBRACE
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list OP_COMMA enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER OP_EQ expr_const
	;

qual_type
	: KEY_CONST
	| KEY_VOLATILE
	;

declarator
	: pointer declarator_direct
	| declarator_direct
	;

declarator_direct
	: IDENTIFIER
	| OP_LPARENTHESES declarator OP_LPARENTHESES
	| declarator_direct OP_LBRACKET expr_const OP_RBRACKET
	| declarator_direct OP_LBRACKET OP_RBRACKET
	| declarator_direct OP_LPARENTHESES parameter_type_list OP_RPARENTHESES
	| declarator_direct OP_LPARENTHESES identifier_list OP_RPARENTHESES
	| declarator_direct OP_LPARENTHESES OP_RPARENTHESES
	;

pointer
	: OP_MULT
	| OP_MULT qual_type_list
	| OP_MULT pointer
	| OP_MULT qual_type_list pointer
	;

qual_type_list
	: qual_type
	| qual_type_list qual_type
	;


parameter_type_list
	: parameter_list
	| parameter_list OP_COMMA OP_ELLIPSIS
	;

parameter_list
	: decl_parameter
	| parameter_list OP_COMMA decl_parameter
	;

decl_parameter
	: decl_specifiers declarator
	| decl_specifiers abstract_declarator
	| decl_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list OP_COMMA IDENTIFIER
	;

type_name
	: qual_specifier_list
	| qual_specifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: OP_LPARENTHESES abstract_declarator OP_RPARENTHESES
	| OP_LBRACKET OP_RBRACKET
	| OP_LBRACKET expr_const OP_RBRACKET
	| direct_abstract_declarator OP_LBRACKET OP_RBRACKET
	| direct_abstract_declarator OP_LBRACKET expr_const OP_RBRACKET
	| OP_LPARENTHESES OP_RPARENTHESES
	| OP_LPARENTHESES parameter_type_list OP_RPARENTHESES
	| direct_abstract_declarator OP_LPARENTHESES OP_RPARENTHESES
	| direct_abstract_declarator OP_LPARENTHESES parameter_type_list OP_RPARENTHESES
	;

initializer
	: expr_assignment
	| OP_LBRACE initializer_list OP_RBRACE
	| OP_LBRACE initializer_list OP_COMMA OP_RBRACE
	;

initializer_list
	: initializer
	| initializer_list OP_COMMA initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expr_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER OP_COLON statement
	| CASE expr_const OP_COLON statement
	| DEFAULT OP_COLON statement
	;

compound_statement
	: OP_LBRACE OP_RBRACE
	| OP_LBRACE statement_list OP_RBRACE
	| OP_LBRACE decl_list OP_RBRACE
	| OP_LBRACE decl_list statement_list OP_RBRACE
	;

decl_list
	: decl
	| decl_list decl
	;

statement_list
	: statement
	| statement_list statement
	;

expr_statement
	: OP_SEMICOLON
	| expr OP_SEMICOLON
	;

selection_statement
	: IF OP_LPARENTHESES expr OP_RPARENTHESES statement
	| IF OP_LPARENTHESES expr OP_RPARENTHESES statement ELSE statement
	| SWITCH OP_LPARENTHESES expr OP_RPARENTHESES statement
	;

iteration_statement
	: WHILE OP_LPARENTHESES expr OP_RPARENTHESES statement
	| DO statement WHILE OP_LPARENTHESES expr OP_RPARENTHESES OP_SEMICOLON
	| FOR OP_LPARENTHESES expr_statement expr_statement OP_RPARENTHESES statement
	| FOR OP_LPARENTHESES expr_statement expr_statement expr OP_RPARENTHESES statement
	;

jump_statement
	: GOTO IDENTIFIER OP_SEMICOLON
	| CONTINUE OP_SEMICOLON
	| BREAK OP_SEMICOLON
	| RETURN OP_SEMICOLON
	| RETURN expr OP_SEMICOLON
	;

translation_unit
	: decl_external
	| translation_unit decl_external
	;

decl_external
	: function_definition
	| decl
	;

function_definition
	: decl_specifiers declarator decl_list compound_statement
	| decl_specifiers declarator compound_statement
	| declarator decl_list compound_statement
	| declarator compound_statement
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}