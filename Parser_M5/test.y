%code requires{
    #include "ast_structure/structures.hpp"
    #include "ast_structure/includes.hpp"
    #include <cassert>

    int yylex();
}

%union {
    const Node* node;
    const Function* funct;
    std::vector<yytokentype> item_list;

    DirectDeclaratorPtr directDeclaratorPtr;

    double double_num;
    int int_num;
    std::string* str;
}


%token IDENTIFIER LIT_DOUBLE LIT_INT LIT_STRING LIT_CHAR SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <directDeclaratorPtr> direct_declarator
%type <node> translation_unit
%type <node> expression assignment_expression unary_expression postfix_expression cast_expression primary_expression
%type <node> multiplicative_expression shift_expression additive_expression relational_expression equality_expression
%type <node> bit_and_expression bit_xor_expression bit_or_expression and_expression or_expression
%type <node> conditional_expression constant_expression declaration declarator initializer
%type <node> storage_class_specifier type_specifier struct_or_union_specifier enum_specifier struct_or_union struct_declaration_list
%type <node> declaration_specifiers struct_declaration specifier_qualifier_list type_qualifier struct_declarator
%type <node> enumerator_list enumerator direct_declarator pointer
%type <node> parameter_declaration init_declarator
%type <node> type_name abstract_declarator direct_abstract_declarator statement compound_statement labeled_statement
%type <node> expression_statement selection_statement iteration_statement jump_statement function_definition

%type <item_list> statement_list parameter_list declaration_list argument_expression_list identifier_list
%type <item_list> init_declarator_list parameter_type_list type_qualifier_list initializer_list

%type <str> assignment_operator unary_operator

%type <str> LIT_STRING IDENTIFIER
%type <int_num> LIT_INT LIT_CHAR 
%type <double_num> LIT_DOUBLE


%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| LIT_CHAR
    | LIT_INT
    | LIT_STRING
    | LIT_DOUBLE
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

bit_and_expression
	: equality_expression
	| bit_and_expression '&' equality_expression
	;

bit_xor_expression
	: bit_and_expression
	| bit_xor_expression '^' bit_and_expression
	;

bit_or_expression
	: bit_xor_expression
	| bit_or_expression '|' bit_xor_expression
	;

and_expression
	: bit_or_expression
	| and_expression AND_OP bit_or_expression
	;

or_expression
	: and_expression
	| or_expression OR_OP and_expression
	;

conditional_expression
	: or_expression
	| or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers // type and pretype
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
    | TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator //pointer is an int
	: pointer direct_declarator         { $$ = new Declarator($1, $2); }
	| direct_declarator                 { $$ = new Declarator(0, $2); }
	;
// Responsible for variable and function names as well as parameters for function
direct_declarator
	: IDENTIFIER                                        { $$ = new IdentifierDeclarator($1); }                      
	| '(' declarator ')'                                { $$ = new ParenthesizedDeclarator($2); }
	| direct_declarator '[' constant_expression ']'     { $$ = new ArrayDeclarator($1, $3); }
	| direct_declarator '[' ']'                         { $$ = new ArrayDeclarator($1, nullptr); }
	| direct_declarator '(' parameter_type_list ')'     { $$ = new FunctionDeclarator($1, $3); }
//used for K&R functions	| direct_declarator '(' identifier_list ')'         { $$ = new DirectDeclarator($1, $3); }
	| direct_declarator '(' ')'                         { $$ = new FunctionDeclarator($1, std::vector<VariablePtr>{}); }
	;

pointer
	: '*'                       { $$ = 1; }
	| '*' pointer               { $$ = $2 + 1; }
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator        //function pointer stuff
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit // START OF PARSING. // RootNode
// translation_unit is root node (therefore root_node.addNode($1))
	: function_definition                               { root_node.addNode($1); }
	| function_definition translation_unit              { root_node.addNode($1); }

	| declaration                                       { root_node.addNode($1); }
	| declaration translation_unit                      { root_node.addNode($1); }
	;


// FUNCTION implementation
function_definition
    // type      and    IDENTIFIER          and         declaration/implementation
	: declaration_specifiers declarator compound_statement      

    // function without type (default return is int)
	| declarator compound_statement                     
	;



%%
#include <stdio.h>


NodePtr parseAST(){
    NodePtr root_node = new Node();
    yyparse();
    return root_node;
}

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}