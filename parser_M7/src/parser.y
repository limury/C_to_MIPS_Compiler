%code requires {


    #include "../include/Node.hpp"
    #include <cassert>

    inline Operator* opGen(OperatorEnum _op){
        return new Operator(_op);
    }

    extern NodePtr root;
//    extern YYSTYPE yylval;

    int yylex(void);
    void yyerror(const char *);

}

%union{
    NodePtr node;
    yytokentype token;
    std::string* string;
}


%type<node> start primary_expression postfix_expression argument_expression_list unary_expression unary_operator cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression assignment_operator expression constant_expression declaration declaration_specifiers init_declarator_list init_declarator storage_class_specifier type_specifier struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier enumerator_list enumerator type_qualifier declarator direct_declarator pointer type_qualifier_list parameter_type_list parameter_list parameter_declaration identifier_list type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition

%token T_IDENTIFIER T_CONSTANT T_STRING_LITERAL 
%type <string> T_IDENTIFIER T_CONSTANT T_STRING_LITERAL 
%token T_PTR_OP T_INC_OP T_DEC_OP T_LEFT_OP T_RIGHT_OP T_LE_OP T_GE_OP T_EQ_OP T_NE_OP T_SIZEOF
%token T_AND_OP T_OR_OP T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN T_ADD_ASSIGN
%token T_SUB_ASSIGN T_LEFT_ASSIGN T_RIGHT_ASSIGN T_AND_ASSIGN
%token T_ADD T_SUB
%token T_XOR_ASSIGN T_OR_ASSIGN T_TYPE_NAME

%token T_TYPEDEF T_EXTERN T_STATIC T_AUTO T_REGISTER
%token T_CHAR T_SHORT T_INT T_LONG T_SIGNED T_UNSIGNED T_FLOAT T_DOUBLE T_CONST T_VOLATILE T_VOID
%token T_STRUCT T_ENUM T_ELLIPSIS

%token T_CASE T_DEFAULT T_IF T_ELSE T_SWITCH T_WHILE T_DO T_FOR T_GOTO T_CONTINUE T_BREAK T_RETURN



%start start
%%

primary_expression
	: T_IDENTIFIER            { $$ = new Node(IDENTIFIER, $1); }
	| T_CONSTANT              { $$ = new Node(CONSTANT, $1); }
	| T_STRING_LITERAL        { $$ = new Node(STRING_LIT, $1); }
	| '(' expression ')'      { $$ = new Node(expression, NodeVec{$2}); }
	;

postfix_expression
	: primary_expression    
	| postfix_expression '[' expression ']'     { $$ = new Node(postfix_expression, NodeVec{ $1, new Operator(L_BRACKET), $3, new Operator(R_BRACKET) }); }
	| postfix_expression '(' ')'        { $$ = new Node(postfix_expression, NodeVec{ $1, new Operator(L_PARENTHESES), new Operator(R_PARENTHESES)}); }
	| postfix_expression '(' argument_expression_list ')'       { $$ = new Node(postfix_expression, NodeVec{ $1, new Operator(L_PARENTHESES), $3, new Operator(R_PARENTHESES) }) ; }
	| postfix_expression '.' T_IDENTIFIER         { $$ = new Node(postfix_expression, NodeVec{$1, new Operator(DOT), new Node(IDENTIFIER, $3)} ); }
	| postfix_expression T_PTR_OP T_IDENTIFIER      { $$ = new Node(   postfix_expression, NodeVec{  $1, new Operator(PTR_OP), new Node(IDENTIFIER, $3)  }   ); }
	| postfix_expression T_INC_OP         { $$ = new Node(postfix_expression, NodeVec{$1, new Operator(INC_OP)}); }
	| postfix_expression T_DEC_OP         { $$ = new Node(postfix_expression, NodeVec{$1, new Operator(DEC_OP)}); }
	;

argument_expression_list
	: assignment_expression             
	| argument_expression_list ',' assignment_expression    { $$ = new Node(argument_expression_list, NodeVec{$1, new Operator(COMMA), $3}); }
	;

unary_expression
	: postfix_expression
	| T_INC_OP unary_expression           { $$ = new Node( unary_expression, NodeVec{new Operator(INC_OP), $2} );}
	| T_DEC_OP unary_expression           { $$ = new Node( unary_expression, NodeVec{new Operator(DEC_OP), $2} );}
	| unary_operator cast_expression    { $$ = new Node( unary_expression, NodeVec{$1, $2} ); }
	| T_SIZEOF unary_expression           { $$ = new Node( unary_expression, NodeVec{new Operator(SIZEOF), $2} ); }
	| T_SIZEOF '(' type_name ')'          { $$ = new Node( unary_expression, NodeVec{new Operator(SIZEOF),new Operator(L_PARENTHESES), $3, new Operator(R_PARENTHESES),} ); }
	;

unary_operator
	: '&'                               { $$ = new Node( unary_operator, NodeVec{new Operator(BIN_AND)} ); }
	| '*'                               { $$ = new Node( unary_operator, NodeVec{new Operator(MULT)} ); }
/*	| T_ADD                               { $$ = new Node( unary_operator, NodeVec{new Operator(PLUS)} ); }*/
	| T_SUB                               { $$ = new Node( unary_operator, NodeVec{new Operator(MINUS)} ); }
	| '~'                               { $$ = new Node( unary_operator, NodeVec{new Operator(BIN_NOT)} ); }
	| '!'                               { $$ = new Node( unary_operator, NodeVec{new Operator(LOGICAL_NOT)} ); }
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression         { $$ = new Node( cast_expression, NodeVec{  new Operator(L_PARENTHESES), $2, new Operator(R_PARENTHESES), $4  } ); }
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression     { $$ = new Node( multiplicative_expression, NodeVec{ $1, opGen(MULT), $3 } ); }
	| multiplicative_expression '/' cast_expression     { $$ = new Node( multiplicative_expression, NodeVec{ $1, opGen(DIVIDE), $3 } ); }
	| multiplicative_expression '%' cast_expression     { $$ = new Node( multiplicative_expression, NodeVec{ $1, opGen(MODULO), $3 } ); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression T_ADD multiplicative_expression     { $$ = new Node( additive_expression, NodeVec{ $1, opGen(PLUS), $3 } ); }
	| additive_expression T_SUB multiplicative_expression     { $$ = new Node( additive_expression, NodeVec{ $1, opGen(MINUS), $3 } ); }
	;

shift_expression
	: additive_expression
	| shift_expression T_LEFT_OP additive_expression      { $$ = new Node( shift_expression, NodeVec{ $1, opGen(LEFT_OP), $3} ); }
	| shift_expression T_RIGHT_OP additive_expression     { $$ = new Node( shift_expression, NodeVec{ $1, opGen(RIGHT_OP), $3} ); }
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression        { $$ = new Node( relational_expression, NodeVec{ $1, opGen(LT), $3 } );}
	| relational_expression '>' shift_expression        { $$ = new Node( relational_expression, NodeVec{ $1, opGen(GT), $3 } );}
	| relational_expression T_LE_OP shift_expression      { $$ = new Node( relational_expression, NodeVec{ $1, opGen(LE_OP), $3 } );}
	| relational_expression T_GE_OP shift_expression      { $$ = new Node( relational_expression, NodeVec{ $1, opGen(GE_OP), $3 } );}
	;

equality_expression
	: relational_expression
	| equality_expression T_EQ_OP relational_expression   { $$ = new Node( equality_expression, NodeVec{ $1, opGen(EQ_OP), $3 } );}
	| equality_expression T_NE_OP relational_expression   { $$ = new Node( equality_expression, NodeVec{ $1, opGen(NE_OP), $3 } );}
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
	| logical_and_expression T_AND_OP inclusive_or_expression { $$ = new Node( logical_and_expression, NodeVec{ $1, opGen(AND_OP), $3 } );}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression T_OR_OP logical_and_expression    { $$ = new Node( logical_or_expression, NodeVec{ $1, opGen(OR_OP), $3 } ); }
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
	| T_MUL_ASSIGN                    { $$ = opGen(MUL_ASSIGN); }
	| T_DIV_ASSIGN                    { $$ = opGen(DIV_ASSIGN); }
	| T_MOD_ASSIGN                    { $$ = opGen(MOD_ASSIGN); }
	| T_ADD_ASSIGN                    { $$ = opGen(ADD_ASSIGN); }
	| T_SUB_ASSIGN                    { $$ = opGen(SUB_ASSIGN); }
	| T_LEFT_ASSIGN                   { $$ = opGen(LEFT_ASSIGN); }
	| T_RIGHT_ASSIGN                  { $$ = opGen(RIGHT_ASSIGN); }
	| T_AND_ASSIGN                    { $$ = opGen(AND_ASSIGN); }
	| T_XOR_ASSIGN                    { $$ = opGen(XOR_ASSIGN); }
	| T_OR_ASSIGN                     { $$ = opGen(OR_ASSIGN); }
	;

expression
	: assignment_expression
	| expression ',' assignment_expression      { $$ = new Node( expression, NodeVec{ $1, opGen(COMMA), $3 } ); }
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'                        { $$ = new Node( declaration, NodeVec{ $1, opGen(SEMICOLON) } );  }
	| declaration_specifiers init_declarator_list ';'   { $$ = new Node( declaration, NodeVec{ $1, $2, opGen(SEMICOLON) } ); }
	;

declaration_specifiers
	: storage_class_specifier                           { $$ = new Node( declaration_specifiers, NodeVec{ $1 } ); }
	| storage_class_specifier declaration_specifiers    { $$ = new Node( declaration_specifiers, NodeVec{ $1, $2 } ); }
	| type_specifier									{ $$ = new Node( declaration_specifiers, NodeVec{ $1 } ); }
	| type_specifier declaration_specifiers             { $$ = new Node( declaration_specifiers, NodeVec{ $1, $2 } ); }
	| type_qualifier									{ $$ = new Node( declaration_specifiers, NodeVec{ $1 } ); }
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
	: T_TYPEDEF                       { $$ = opGen(TYPEDEF); }
	| T_EXTERN                        { $$ = opGen(EXTERN); }
	| T_STATIC                        { $$ = opGen(STATIC); }
	| T_AUTO                          { $$ = opGen(AUTO); }
	| T_REGISTER                      { $$ = opGen(REGISTER); }
	;

type_specifier
	: T_VOID                          { $$ = opGen(VOID); }
	| T_CHAR                          { $$ = opGen(CHAR); }
	| T_SHORT                         { $$ = opGen(SHORT); }
	| T_INT                           { $$ = opGen(INT); }
	| T_LONG                          { $$ = opGen(LONG); }
	| T_FLOAT                         { $$ = opGen(FLOAT); }
	| T_DOUBLE                        { $$ = opGen(DOUBLE); }
	| T_SIGNED                        { $$ = opGen(SIGNED); }
	| T_UNSIGNED                      { $$ = opGen(UNSIGNED); }
	| struct_or_union_specifier     
	| enum_specifier
	| T_TYPE_NAME                     { $$ = opGen(TYPE_NAME); }
	;

struct_or_union_specifier
	: struct_or_union T_IDENTIFIER '{' struct_declaration_list '}'    { $$ = new Node( struct_or_union_specifier, NodeVec{ $1, new Node(IDENTIFIER, $2), opGen(L_BRACE), $4, opGen(R_BRACE)  } ); }
	| struct_or_union '{' struct_declaration_list '}'       { $$ = new Node( struct_or_union_specifier, NodeVec{ $1, opGen(L_BRACE), $3, opGen(R_BRACE) } ); }
	| struct_or_union T_IDENTIFIER            { $$ = new Node( struct_or_union_specifier, NodeVec{ $1, new Node(IDENTIFIER, $2) } ); }
	;

struct_or_union
	: T_STRUCT            { $$ = opGen(STRUCT); }
	| T_VOLATILE             { $$ = opGen(UNION); }
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
	: T_ENUM '{' enumerator_list '}'              { $$ = new Node( enum_specifier, NodeVec{ opGen(ENUM), opGen(L_BRACE), $3, opGen(R_BRACE) } ); }
	| T_ENUM T_IDENTIFIER '{' enumerator_list '}'   { $$ = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, $2 ), opGen(L_BRACE), $4, opGen(R_BRACE) } ); }
	| T_ENUM T_IDENTIFIER                           { $$ = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, $2 ) } ); }
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator            { $$ = new Node( enumerator_list, NodeVec{ $1, opGen(COMMA), $3 } ) ; }
	;

enumerator
	: T_IDENTIFIER                { $$ = new Node( IDENTIFIER, $1 ); }
	| T_IDENTIFIER '=' constant_expression        { $$ = new Node( enumerator, NodeVec{ new Node(IDENTIFIER, $1), opGen(EQUALS), $3 } ); }
	;

type_qualifier
	: T_CONST             { $$ = opGen(CONST); }
	| T_VOLATILE          { $$ = opGen(VOLATILE); }
	;

declarator
	: pointer direct_declarator         { $$ = new Node( declarator, NodeVec{ $1, $2 } ); }
	| direct_declarator
	;

direct_declarator
	: T_IDENTIFIER                        { $$ = new Node(IDENTIFIER, $1); }
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
	| parameter_list ',' T_ELLIPSIS           { $$ = new Node( parameter_type_list, NodeVec{ $1, opGen(COMMA), opGen(ELLIPSIS) } ); }
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
	: T_IDENTIFIER                            { $$ = new Node( IDENTIFIER, $1 ); }
	| identifier_list ',' T_IDENTIFIER        { $$ = new Node( identifier_list, NodeVec{ $1, opGen(COMMA), new Node(IDENTIFIER, $3) } ); }
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
	: T_IDENTIFIER ':' statement          { $$ = new Node( labeled_statement, NodeVec{ new Node(IDENTIFIER, $1), opGen(COLON), $3 } ); }
	| T_CASE constant_expression ':' statement    { $$ = new Node( labeled_statement, NodeVec{ opGen(CASE), $2, opGen(COLON), $4 } ); }
	| T_DEFAULT ':' statement             { $$ = new Node( labeled_statement, NodeVec{ opGen(DEFAULT), opGen(COLON), $3 } ); }
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
	: ';'       { $$ = opGen(SEMICOLON); }
	| expression ';'                { $$ = new Node( expression_statement, NodeVec{ $1, opGen(SEMICOLON) } ); }
	;

selection_statement
	: T_IF '(' expression ')' statement                   { $$ = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5 } ); }
	| T_IF '(' expression ')' statement T_ELSE statement    { $$ = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5, opGen(ELSE), $7 } ); }
	| T_SWITCH '(' expression ')' statement           { $$ = new Node( selection_statement, NodeVec{ opGen(SWITCH), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5 } ); }
	;

iteration_statement
	: T_WHILE '(' expression ')' statement            { $$ = new Node( iteration_statement, NodeVec{ opGen(WHILE), opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES), $5 } ); }
	| T_DO statement T_WHILE '(' expression ')' ';'     { $$ = new Node( iteration_statement, NodeVec{ opGen(DO), $2, opGen(WHILE), opGen(L_PARENTHESES), $5, opGen(R_PARENTHESES), opGen(SEMICOLON) } ); }
	| T_FOR '(' expression_statement expression_statement ')' statement   { $$ = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), $3, $4, opGen(R_PARENTHESES), $6 } ); }
	| T_FOR '(' expression_statement expression_statement expression ')' statement    { $$ = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), $3, $4, $5, opGen(R_PARENTHESES), $7 } ); }
	;

jump_statement
	: T_GOTO T_IDENTIFIER ';'       { $$ = new Node( jump_statement, NodeVec{ opGen(GOTO), new Node(IDENTIFIER, $2), opGen(SEMICOLON) } ); }
	| T_CONTINUE ';'              { $$ = new Node( jump_statement, NodeVec{ opGen(CONTINUE), opGen(SEMICOLON) } ); }
	| T_BREAK ';'                 { $$ = new Node( jump_statement, NodeVec{ opGen(BREAK), opGen(SEMICOLON) } ); }
	| T_RETURN ';'                { $$ = new Node( jump_statement, NodeVec{ opGen(RETURN), opGen(SEMICOLON) } ); }
	| T_RETURN expression ';'     { $$ = new Node( jump_statement, NodeVec{ opGen(RETURN), $2, opGen(SEMICOLON) } ); }
	;

start
    : translation_unit { root = $1; }

translation_unit
	: external_declaration         
	| translation_unit external_declaration     { $$ = new Node( translation_unit, NodeVec{ $1, $2 } ); }
	;

external_declaration
	: function_definition
	| declaration    { $$ = $1; }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement     {  $$ = new Node( function_definition, NodeVec{ $1, $2, $3, $4 } ); }
	| declaration_specifiers declarator compound_statement      {  $$ = new Node( function_definition, NodeVec{ $1, $2, $3 } ); }
	| declarator declaration_list compound_statement        {  $$ = new Node( function_definition, NodeVec{ $1, $2, $3 } ); }
	| declarator compound_statement                { $$ = new Node( function_definition, NodeVec{ $1, $2 } ); }
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

NodePtr root;

NodePtr parseAST(){
    root == nullptr;
    std::cout << "Parsing beginning" << std::endl;
    yyparse();
    std::cout << "Parsing done" << std::endl;
    
    return root;
}
