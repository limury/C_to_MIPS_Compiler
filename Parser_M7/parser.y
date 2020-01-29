%code requires {

    #define YYSTYPE string

    #include "Node.hpp"

    int yylex(void);
    void yyerror(char const*)

}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER            { $$ = new Node(IDENTIFIER, $1); }
	| CONSTANT              { $$ = new Node(CONSTANT, $1); }
	| STRING_LITERAL        { $$ = new Node(STRING_LIT, $1); }
	| '(' expression ')'    { $$ = new Node(expression, new std::vector<NodePtr>{$2}); }
	;

postfix_expression
	: primary_expression    
	| postfix_expression '[' expression ']'     { $$ = new Node(postfix_expression, new std::vector<NodePtr>{ $1, new Operator(L_BRACKET), $3, new Operator(R_BRACKET) }); }
	| postfix_expression '(' ')'        { $$ = new Node(postfix_expression, new std::vector<NodePtr>{ $1, new Operator(L_PARENTHESES), new Operator(R_PARENTHESES)}); }
	| postfix_expression '(' argument_expression_list ')'       { $$ = new Node(postfix_expression, NodeVec{ $1, new Operator('('), $3, new Operator(')') }) ; }
	| postfix_expression '.' IDENTIFIER         { $$ = new Node(postfix_expression, NodeVec{$1, new Operator('.'), $3}); }
	| postfix_expression PTR_OP IDENTIFIER      { $$ = new Node(   postfix_expression, NodeVec{  $1, new Operator(PTR_OP), new Node(IDENTIFIER, $3)  }   ); }
	| postfix_expression INC_OP         { $$ = new Node(postfix_expression, NodeVec{$1, new Operator(INC_OP)}); }
	| postfix_expression DEC_OP         { $$ = new Node(postfix_expression, NodeVec{$1, new Operator(DEC_OP)}); }
	;

argument_expression_list
	: assignment_expression             
	| argument_expression_list ',' assignment_expression    { $$ = new Node(argument_expression_list, NodeVec{$1, new Operator(COMMA), $3}); }
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression           { $$ = new Node( unary_expression, NodeVec{new Operator(INC_OP), $2} );}
	| DEC_OP unary_expression           { $$ = new Node( unary_expression, NodeVec{new Operator(DEC_OP), $2} );}
	| unary_operator cast_expression    { $$ = new Node( unary_expression, NodeVec{$1, $2} ); }
	| SIZEOF unary_expression           { $$ = new Node( unary_expression, NodeVec{new Operator(SIZEOF), $2} ); }
	| SIZEOF '(' type_name ')'          { $$ = new Node( unary_expression, NodeVec{new Operator(SIZEOF),new Operator('('), $3, new Operator(')'),} ); }
	;

unary_operator
	: '&'                               { $$ = new Node( unary_operator, NodeVec{new Operator(BIN_AND)} ); }
	| '*'                               { $$ = new Node( unary_operator, NodeVec{new Operator(MULT)} ); }
	| '+'                               { $$ = new Node( unary_operator, NodeVec{new Operator(PLUS)} ); }
	| '-'                               { $$ = new Node( unary_operator, NodeVec{new Operator(MINUS)} ); }
	| '~'                               { $$ = new Node( unary_operator, NodeVec{new Operator(BIN_NOT)} ); }
	| '!'                               { $$ = new Node( unary_operator, NodeVec{new Operator(LOGICAL_NOT)} ); }
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression         { $$ = new Node( cast_expression, NodeVec{  new Operator('('), $2, new Operator(')'), $4  } ); }
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression     { $$ = new Node( multiplicative_expression, NodeVec{ $1, opGen(MULT), $3 } ); }
	| multiplicative_expression '/' cast_expression     { $$ = new Node( multiplicative_expression, NodeVec{ $1, opGen(DIVIDE), $3 } ); }
	| multiplicative_expression '%' cast_expression     { $$ = new Node( multiplicative_expression, NodeVec{ $1, opGen(MODULO), $3 } ); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression     { $$ = new Node( additive_expression, NodeVec{ $1, opGen(PLUS), $3 } ); }
	| additive_expression '-' multiplicative_expression     { $$ = new Node( additive_expression, NodeVec{ $1, opGen(MINUS), $3 } ); }
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression      { $$ = new Node( shift_expression, NodeVec{ $1, opGen(LEFT_OP), $3} ); }
	| shift_expression RIGHT_OP additive_expression     { $$ = new Node( shift_expression, NodeVec{ $1, opGen(RIGHT_OP), $3} ); }
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression        { $$ = new Node( relational_expression, NodeVec{ $1, opGen(LT), $3 } );}
	| relational_expression '>' shift_expression        { $$ = new Node( relational_expression, NodeVec{ $1, opGen(GT), $3 } );}
	| relational_expression LE_OP shift_expression      { $$ = new Node( relational_expression, NodeVec{ $1, opGen(LE_OP), $3 } );}
	| relational_expression GE_OP shift_expression      { $$ = new Node( relational_expression, NodeVec{ $1, opGen(GE_OP), $3 } );}
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression   { $$ = new Node( equality_expression, NodeVec{ $1, opGen(EQ_OP), $3 } );}
	| equality_expression NE_OP relational_expression   { $$ = new Node( equality_expression, NodeVec{ $1, opGen(NE_OP), $3 } );}
	;

and_expression
	: equality_expression                               
	| and_expression '&' equality_expression            { $$ = new Node( and_expression, NodeVec{ $1, opGen(BIN_AND), $3 } );}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression        { $$ = new Node( exclusive_or_expression, NodeVec{ $1, opGen(BIN_XOR), $3 } );}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression   { $$ = new Node( inclusive_or_expression, NodeVec{ $1, opGen(BIN_OR), $3 } );}
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression { $$ = new Node( logical_and_expression, NodeVec{ $1, opGen(AND_OP), $3 } );}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression    { $$ = new Node( logical_or_expression, NodeVec{ $1, opGen(OR_OP), $3 } );}
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression   { $$ = new Node( conditional_expression, NodeVec{ $1, opGen(QUESTION_MARK), $3, opGen(COLON), $5 } );}
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression    { $$ = new Node( relational_expression, NodeVec{ $1, $2, $3 } );}
	;

assignment_operator
	: '='                           { $$ = opGen(EQUALS); }
	| MUL_ASSIGN                    { $$ = opGen(MUL_ASSIGN); }
	| DIV_ASSIGN                    { $$ = opGen(DIV_ASSIGN); }
	| MOD_ASSIGN                    { $$ = opGen(MOD_ASSIGN); }
	| ADD_ASSIGN                    { $$ = opGen(ADD_ASSIGN); }
	| SUB_ASSIGN                    { $$ = opGen(SUB_ASSIGN); }
	| LEFT_ASSIGN                   { $$ = opGen(LEFT_ASSIGN); }
	| RIGHT_ASSIGN                  { $$ = opGen(RIGHT_ASSIGN); }
	| AND_ASSIGN                    { $$ = opGen(AND_ASSIGN); }
	| XOR_ASSIGN                    { $$ = opGen(XOR_ASSIGN); }
	| OR_ASSIGN                     { $$ = opGen(OR_ASSIGN); }
	;

expression
	: assignment_expression
	| expression ',' assignment_expression      { $$ = new Node( expression, NodeVec{ $1, opGen(COMMA), $3 } ); }
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'                        { $$ = new Node( declaration, NodeVec{ $1, opGen(SEMICOLON) } ); }
	| declaration_specifiers init_declarator_list ';'   { $$ = new Node( declaration, NodeVec{ $1, $2, opGen(SEMICOLON) } ); }
	;

declaration_specifiers
	: storage_class_specifier                           
	| storage_class_specifier declaration_specifiers    { $$ = new Node( declaration_specifiers, NodeVec{ $1, $2 } ); }
	| type_specifier
	| type_specifier declaration_specifiers             { $$ = new Node( declaration_specifiers, NodeVec{ $1, $2 } ); }
	| type_qualifier
	| type_qualifier declaration_specifiers             { $$ = new Node( declaration_specifiers, NodeVec{ $1, $2 } ); }
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator          { $$ = new Node( init_declarator_list, NodeVec{ $1, opGen(COMMA), $3 } ); }
	;

init_declarator
	: declarator
	| declarator '=' initializer            { $$ = new Node( init_declarator, NodeVec{ $1, opGen(EQUALS), $3 } ); }
	;

storage_class_specifier
	: TYPEDEF                       { $$ = opGen(TYPEDEF); }
	| EXTERN                        { $$ = opGen(EXTERN); }
	| STATIC                        { $$ = opGen(STATIC); }
	| AUTO                          { $$ = opGen(AUTO); }
	| REGISTER                      { $$ = opGen(REGISTER); }
	;

type_specifier
	: VOID                          { $$ = opGen(VOID); }
	| CHAR                          { $$ = opGen(CHAR); }
	| SHORT                         { $$ = opGen(SHORT); }
	| INT                           { $$ = opGen(INT); }
	| LONG                          { $$ = opGen(LONG); }
	| FLOAT                         { $$ = opGen(FLOAT); }
	| DOUBLE                        { $$ = opGen(DOUBLE); }
	| SIGNED                        { $$ = opGen(SIGNED); }
	| UNSIGNED                      { $$ = opGen(UNSIGNED); }
	| struct_or_union_specifier     
	| enum_specifier
	| TYPE_NAME                     { $$ = opGen(TYPE_NAME); }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'    { $$ = new Node( struct_or_union_specifier, NodeVec{ $1, new Node(IDENTIFIER, $2), opGen(L_BRACE), $4, opGen(R_BRACE)  } ); }
	| struct_or_union '{' struct_declaration_list '}'       { $$ = new Node( struct_or_union_specifier, NodeVec{ $1, opGen(L_BRACE), $3, opGen(R_BRACE) } ); }
	| struct_or_union IDENTIFIER            { $$ = new Node( struct_or_union_specifier, NodeVec{ $1, new Node(IDENTIFIER, $2) } ); }
	;

struct_or_union
	: STRUCT            { $$ = opGen(STRUCT); }
	| UNION             { $$ = opGen(UNION); }
	;

struct_declaration_list
	: struct_declaration                             
	| struct_declaration_list struct_declaration    { $$ = new Node( struct_declaration_list, NodeVec{ $1, $2 } ); }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'   { $$ = new Node( struct_declaration, NodeVec{ $1, $2, opGen(SEMICOLON) } ); }
	;

specifier_qualifier_list                             
	: type_specifier specifier_qualifier_list       { $$ = new Node( specifier_qualifier_list, NodeVec{ $1, $2 } ); }
	| type_specifier
	| type_qualifier specifier_qualifier_list       { $$ = new Node( specifier_qualifier_list, NodeVec{ $1, $2 } ); }
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator  { $$ = new Node( struct_declarator_list, NodeVec{ $1, opGen(COMMA), $3 } ); }
	;

struct_declarator
	: declarator
	| ':' constant_expression               { $$ = new Node( struct_declarator, NodeVec{ opGen(COLON), $2 } ); }
	| declarator ':' constant_expression    { $$ = new Node( struct_declarator, NodeVec{ $1, opGen(COLON), $3 } ); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'              { $$ = new Node( enum_specifier, NodeVec{ opGen(ENUM), opGen(L_BRACE), $3, opGen(R_BRACE) } ); }
	| ENUM IDENTIFIER '{' enumerator_list '}'   { $$ = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, $2 ), opGen(L_BRACE), $4, opGen(R_BRACE) } ); }
	| ENUM IDENTIFIER                           { $$ = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, $2 ) } ); }
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator            { $$ = new Node( enumerator_list, NodeVec{ $1, opGen(COMMA), $3 } ) ; }
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression        { $$ = new Node( enumerator, NodeVec{ new Node(IDENTIFIER, $1), opGen(EQUALS), $3 } ); }
	;

type_qualifier
	: CONST             { $$ = opGen(CONST); }
	| VOLATILE          { $$ = opGen(VOLATILE); }
	;

declarator
	: pointer direct_declarator         { $$ = new Node( declarator, NodeVec{ $1, $2 } ); }
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER                        { $$ = new Node(IDENTIFIER, $1); }
	| '(' declarator ')'                                { $$ = new Node( direct_declarator, NodeVec{ opGen(L_PARENTHESES), $2, opGen(R_PARENTHESES) } ); }
	| direct_declarator '[' constant_expression ']'     { $$ = new Node( direct_declarator, NodeVec{ $1, opGen(L_BRACKET), $3, opGen(R_BRACKET) } ); }
	| direct_declarator '[' ']'                         { $$ = new Node( direct_declarator, NodeVec{ $1, opGen(L_BRACKET), opGen(R_BRACKET) } ); }
	| direct_declarator '(' parameter_type_list ')'     { $$ = new Node( direct_declarator, NodeVec{ $1, opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES) } ); }
	| direct_declarator '(' identifier_list ')'         { $$ = new Node( direct_declarator, NodeVec{ $1, opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES) } ); }
	| direct_declarator '(' ')'                         { $$ = new Node( direct_declarator, NodeVec{ $1, opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
	;

pointer
	: '*'                                   { $$ = opGen(MULT); }
	| '*' type_qualifier_list               { $$ = new Node( pointer, NodeVec{ opGen(MULT), $2 } ); }
	| '*' pointer                           { $$ = new Node( pointer, NodeVec{ opGen(MULT), $2 } ); }
	| '*' type_qualifier_list pointer       { $$ = new Node( pointer, NodeVec{ opGen(MULT), $2, $3 } ); }
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier    { $$ = new Node( type_qualifier_list, NodeVec{ $1, $2 } ); }
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS           { $$ = new Node( parameter_type_list, NodeVec{ $1, opGen(COMMA), opGen(ELLIPSIS) } ); }
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration      { $$ = new Node( parameter_list, NodeVec{ $1, opGen(COMMA), $3 } ); }
	;

parameter_declaration
	: declaration_specifiers declarator             { $$ = new Node( parameter_declaration, NodeVec{ $1, $2 } ); }
	| declaration_specifiers abstract_declarator    { $$ = new Node( parameter_declaration, NodeVec{ $1, $2 } ); }
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER                            { $$ = new Node( IDENTIFIER, $1 ); }
	| identifier_list ',' IDENTIFIER        { $$ = new Node( identifier_list, NodeVec{ $1, opGen(COMMA), $3 } ); }
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator  { $$ = new Node( type_name, NodeVec{ $1, $2 } ); }
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator            { $$ = new Node( abstract_declarator, NodeVec{ $1, $2 } ); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'                   { $$ = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), $2, opGen(R_PARENTHESES) } ); }
	| '[' ']'                                       { $$ = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), opGen(R_BRACKET) } ); }
	| '[' constant_expression ']'                   { $$ = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), $2, opGen(R_BRACKET) } ); }
	| direct_abstract_declarator '[' ']'            { $$ = new Node( direct_abstract_declarator, NodeVec{ $1, opGen(L_BRACKET), opGen(R_BRACKET) } ); }
	| direct_abstract_declarator '[' constant_expression ']'        { $$ = new Node( direct_abstract_declarator, NodeVec{ $1, opGen(L_BRACKET), $3, opGen(R_BRACKET) } ); }
	| '(' ')'                                       { $$ = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
	| '(' parameter_type_list ')'                   { $$ = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), $2, opGen(R_PARENTHESES) } ); }
	| direct_abstract_declarator '(' ')'            { $$ = new Node( direct_abstract_declarator, NodeVec{ $1, opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
	| direct_abstract_declarator '(' parameter_type_list ')'        { $$ = new Node( direct_abstract_declarator, NodeVec{ $1, opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES) } ); }
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'              { $$ = new Node( initializer, NodeVec{ opGen(L_BRACE), $2, opGen(R_BRACE) } ); }
	| '{' initializer_list ',' '}'          { $$ = new Node( initializer, NodeVec{ opGen(L_BRACE), $2, opGen(COMMA), opGen(R_BRACE) } ); }
	;

initializer_list
	: initializer
	| initializer_list ',' initializer      { $$ = new Node( initializer_list, NodeVec{ $1, opGen(COMMA), $3 } ); }
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
	: IDENTIFIER ':' statement          { $$ = new Node( labeled_statement, NodeVec{ new Node(IDENTIFIER, $1), opGen(COLON), $3 } ); }
	| CASE constant_expression ':' statement    { $$ = new Node( labeled_statement, NodeVec{ opGen(CASE), $2, opGen(COLON), $4 } ); }
	| DEFAULT ':' statement             { $$ = new Node( labeled_statement, NodeVec{ opGen(DEFAULT), opGen(COLON), $3 } ); }
	;

compound_statement
	: '{' '}'                   { $$ = new Node( compound_statement, NodeVec{ opGen(L_BRACE), opGen(R_BRACE) } ); }
	| '{' statement_list '}'    { $$ = new Node( compound_statement, NodeVec{ opGen(L_BRACE), $2, opGen(R_BRACE) } ); }
	| '{' declaration_list '}'  { $$ = new Node( compound_statement, NodeVec{ opGen(L_BRACE), $2, opGen(R_BRACE) } ); }
	| '{' declaration_list statement_list '}'   { $$ = new Node( compound_statement, NodeVec{ opGen(L_BRACE), $2, $3, opGen(R_BRACE) } ); }
	;

declaration_list
	: declaration
	| declaration_list declaration  { $$ = new Node( declaration_list, NodeVec{ $1, $2 } ); }
	;

statement_list
	: statement
	| statement_list statement      { $$ = new Node( statement_list, NodeVec{ $1, $2 } ); }
	;

expression_statement
	: ';'
	| expression ';'                { $$ = new Node( expression_statement, NodeVec{ $1, opGen(SEMICOLON) } ); }
	;

selection_statement
	: IF '(' expression ')' statement                   { $$ = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5 } ); }
	| IF '(' expression ')' statement ELSE statement    { $$ = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5, opGen(ELSE), $7 } ); }
	| SWITCH '(' expression ')' statement           { $$ = new Node( selection_statement, NodeVec{ opGen(SWITCH), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5 } ); }
	;

iteration_statement
	: WHILE '(' expression ')' statement            { $$ = new Node( iteration_statement, NodeVec{ opGen(WHILE), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5 } ); }
	| DO statement WHILE '(' expression ')' ';'     { $$ = new Node( iteration_statement, NodeVec{ opGen(DO), $2, opGen(WHILE), opGen(L_PARENTHESES), $5, opGen(R_PARENTHESES), opGen(SEMICOLON) } ); }
	| FOR '(' expression_statement expression_statement ')' statement   { $$ = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), $3, $4, opGen(R_PARENTHESES), $6 } ); }
	| FOR '(' expression_statement expression_statement expression ')' statement    { $$ = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), $3, $4, $5, opGen(R_PARENTHESES), $7 } ); }
	;

jump_statement
	: GOTO IDENTIFIER ';'       { $$ = new Node( jump_statement, NodeVec{ opGen(GOTO), new Node(IDENTIFIER, $2), opGen(SEMICOLON) } ); }
	| CONTINUE ';'              { $$ = new Node( jump_statement, NodeVec{ opGen(CONTINUE), opGen(SEMICOLON) } ); }
	| BREAK ';'                 { $$ = new Node( jump_statement, NodeVec{ opGen(BREAK), opGen(SEMICOLON) } ); }
	| RETURN ';'                { $$ = new Node( jump_statement, NodeVec{ opGen(RETURN), opGen(SEMICOLON) } ); }
	| RETURN expression ';'     { $$ = new Node( jump_statement, NodeVec{ opGen(RETURN), $2, opGen(SEMICOLON) } ); }
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration     { $$ = new Node( translation_unit, NodeVec{ $1, $2 } ); }
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement     { $$ = new Node( function_definition, NodeVec{ $1, $2, $3, $4 } ); }
	| declaration_specifiers declarator compound_statement      { $$ = new Node( function_definition, NodeVec{ $1, $2, $3 } ); }
	| declarator declaration_list compound_statement        { $$ = new Node( function_definition, NodeVec{ $1, $2, $3 } ); }
	| declarator compound_statement                { $$ = new Node( function_definition, NodeVec{ $1, $2 } ); }
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