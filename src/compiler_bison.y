%code requires{
    #include "ast.hpp"

    #include <cassert>
    #include <fstream>

    extern FILE *yyin;
    extern AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);
}
%define parse.error verbose

%union{
    std::string *string;
    double number;

    BaseNode *BaseNodePtr;
    BaseExpression *BaseExpressionPtr;
    BaseList *BaseListPtr;
    BaseExpressionList *BaseExpressionListPtr;
}

%token STRING_LITERAL
%token PLUSPLUS MINUSMINUS
%token EQUAL_TO NOT_EQUAL_TO LESS_THAN_EQUAL MORE_THAN_EQUAL
%token AND OR
%token LEFT_SHIFT RIGHT_SHIFT
%token PLUS_EQUAL MINUS_EQUAL TIMES_EQUAL DIVIDE_EQUAL MOD_EQUAL
%token LEFT_SHIFT_EQUAL RIGHT_SHIFT_EQUAL B_AND_EQUAL XOR_EQUAL B_OR_EQUAL
%token ARROW
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE
%token ENUM FLOAT FOR GOTO IF INT LONG REGISTER RETURN
%token SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION
%token UNSIGNED VOID WHILE EXTERN VOLATILE
%token NUMBER IDENTIFIER TYPEDEF_T

%type <string> IDENTIFIER STRING_LITERAL CONST VOLATILE TYPEDEF_T
%type <number> NUMBER
%type <BaseListPtr> argument_expression_list statement_list declaration_list parameter_list pointer enum_list struct_declarator_list struct_declaration_list specifier_list init_declarator_list translation_unit
%type <BaseExpressionPtr> expression conditional_expression logical_or_expression logical_and_expression inclusive_or_expression exclusive_or_expression and_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression unary_expression postfix_expression primary_expression initializer
%type <BaseNodePtr> statement labeled_statement compound_statement expression_statement selection_statement iteration_statement jump_statement direct_abstract_declarator abstract_declarator type_name parameter_declaration direct_declarator declarator enumerator enum_specifier struct_declarator struct_declaration struct_spec type_specifier init_declarator declaration_specifier declaration function_definition external_declaration top_container
%type <BaseExpressionListPtr> initializer_list

%nonassoc NOELSE
%nonassoc ELSE

%start ROOT

%%

ROOT : top_container { g_root = $1; }

//**************************************************************************************
//----------------------------------------- TOP ----------------------------------------
//**************************************************************************************
top_container : translation_unit { $$ = new TopContainer($1); }
              ;

translation_unit : external_declaration                     { $$ = new TranslationUnit(NULL, $1); }
                 | translation_unit external_declaration    { $$ = new TranslationUnit($1, $2); }
                 ;

external_declaration : function_definition  { $$ = $1; }
                     | declaration          { $$ = $1; }
                     ;

function_definition : declaration_specifier declarator compound_statement   { $$ = new FunctionDefinition($1, $2, $3); }
                    | declarator compound_statement                         { $$ = new FunctionDefinition($1, $2); }
                    ;

//**************************************************************************************
//------------------------------------- DECLARATIONS -----------------------------------
//**************************************************************************************

declaration : declaration_specifier ';'                      { $$ = $1; }
            | declaration_specifier init_declarator_list ';' { $$ = new Declaration($1, $2); }
            ;

declaration_specifier : TYPEDEF declaration_specifier           { $$ = new TypeDefDecSpec($2); }
                      | TYPEDEF                                 { $$ = new TypeDefDecSpec(NULL); }
                      | type_specifier declaration_specifier    { $$ = new TypeSpecDecSpec($2, $1); }
                      | type_specifier                          { $$ = $1; }
                      ;

init_declarator_list : init_declarator                              { $$ = new InitDecList(NULL, $1); }
                     | init_declarator_list ',' init_declarator     { $$ = new InitDecList($1, $3); }
                     ;

init_declarator : declarator                    { $$ = $1; }
                | declarator '=' initializer    { $$ = new InitDeclarator($1, $3); }
                ;

type_specifier : VOID           { $$ = new BasicTypeSpec(VOID_T); }
               | CHAR           { $$ = new BasicTypeSpec(CHAR_T); }
               | SHORT          { $$ = new BasicTypeSpec(SHORT_T); }
               | INT            { $$ = new BasicTypeSpec(INT_T); }
               | LONG           { $$ = new BasicTypeSpec(LONG_T); }
               | FLOAT          { $$ = new BasicTypeSpec(FLOAT_T); }
               | DOUBLE         { $$ = new BasicTypeSpec(DOUBLE_T); }
               | SIGNED         { $$ = new BasicTypeSpec(SIGNED_T); }
               | UNSIGNED       { $$ = new BasicTypeSpec(UNSIGNED_T); }
               | struct_spec    { $$ = $1; }
               | enum_specifier { $$ = $1; }
               | TYPEDEF_T      { $$ = new TypeDefTypeSpec(*$1); }
               ;

specifier_list : type_specifier specifier_list  { $$ = new TypeSpecList($2, $1); }
               | type_specifier                 { $$ = new TypeSpecList(NULL, $1); }
               ;

struct_spec : STRUCT IDENTIFIER '{' struct_declaration_list '}' { $$ = new StructSpecifier(*$2, $4); }
            | STRUCT '{' struct_declaration_list '}'            { $$ = new StructSpecifier($3); }
            | STRUCT IDENTIFIER                                 { $$ = new StructSpecifier(*$2, NULL); }
            ;

struct_declaration_list : struct_declaration                            { $$ = new StructDeclarationList(NULL, $1); }
                        | struct_declaration_list struct_declaration    { $$ = new StructDeclarationList($1, $2); }

struct_declaration : specifier_list struct_declarator_list ';' { $$ = new StructDeclaration($1, $2); }
	               ;

struct_declarator_list : struct_declarator                              { $$ = new StructDeclaratorList(NULL, $1); }
                       | struct_declarator_list ',' struct_declarator   { $$ = new StructDeclaratorList($1, $3); }
                       ;

struct_declarator : declarator                  { $$ = $1; }
                  | ':' expression              { $$ = new StructDeclarator(NULL, $2); }
                  | declarator ':' expression   { $$ = new StructDeclarator($1, $3); }
                  ;

enum_specifier : ENUM '{' enum_list '}'             { $$ = new EnumSpecifier($3); }
               | ENUM IDENTIFIER '{' enum_list '}'  { $$ = new EnumSpecifier(*$2, $4); }
               | ENUM IDENTIFIER                    { $$ = new EnumSpecifier(*$2, NULL); }
               ;

enum_list : enumerator                  { $$ = new EnumElemList(NULL, $1); }
          | enum_list ',' enumerator    { $$ = new EnumElemList($1, $3); }
          ;

enumerator : IDENTIFIER                 { $$ = new EnumElement(*$1, NULL); }
           | IDENTIFIER '=' expression  { $$ = new EnumElement(*$1, $3); }
           ;

declarator : pointer direct_declarator  { $$ = new Declarator($1, $2); }
           | direct_declarator          { $$ = $1; }
           ;

direct_declarator : IDENTIFIER                                  { $$ = new DeclaratorIdentifier(*$1); }
                  | '(' declarator ')'                          { $$ = $2; }
                  | direct_declarator '[' expression ']'        { $$ = new DeclaratorArray($1, $3); }
                  | direct_declarator '[' ']'                   { $$ = new DeclaratorArray($1, NULL); }
                  | direct_declarator '(' parameter_list ')'    { $$ = new DeclaratorFunc($1, $3); }
                  | direct_declarator '(' ')'                   { $$ = new DeclaratorFunc($1, NULL); }
                  ;

pointer : '*'           { $$ = new Pointer(NULL); }
        | '*' pointer   { $$ = new Pointer($2); }
	    ;

parameter_list : parameter_declaration                      { $$ = new ParamList(NULL, $1); }
               | parameter_list ',' parameter_declaration   { $$ = new ParamList($1, $3); }
               ;

parameter_declaration : declaration_specifier declarator            { $$ = new ParamDeclaration($1, $2, NULL); }
                      | declaration_specifier abstract_declarator   { $$ = new ParamDeclaration($1, NULL, $2); }
                      | declaration_specifier                       { $$ = new ParamDeclaration($1, NULL, NULL); }
                      ;

type_name : specifier_list                      { $$ = new TypeName($1, NULL); }
	      | specifier_list abstract_declarator  { $$ = new TypeName($1, $2); }
	      ;

abstract_declarator : pointer                               { $$ = new AbstractDeclarator($1, NULL); }
                    | direct_abstract_declarator            { $$ = new AbstractDeclarator(NULL, $1); }
                    | pointer direct_abstract_declarator    { $$ = new AbstractDeclarator($1, $2); }
                    ;

direct_abstract_declarator : '(' abstract_declarator ')'                        { $$ = $2; }
                           | '[' ']'                                            { $$ = new AbstractArray(NULL, NULL); }
                           | '[' expression ']'                                 { $$ = new AbstractArray(NULL, $2); }
                           | direct_abstract_declarator '[' ']'                 { $$ = new AbstractArray($1, NULL); }
                           | direct_abstract_declarator '[' expression ']'      { $$ = new AbstractArray($1, $3); }
                           | '(' ')'                                            { $$ = new AbstractFunc(NULL, NULL); }
                           | '(' parameter_list ')'                             { $$ = new AbstractFunc(NULL, $2); }
                           | direct_abstract_declarator '(' ')'                 { $$ = new AbstractFunc($1, NULL); }
                           | direct_abstract_declarator '(' parameter_list ')'  { $$ = new AbstractFunc($1, $3); }
                           ;

initializer : expression                    { $$ = $1; }
            | '{' initializer_list '}'      { $$ = new InitializerListHolder($2); }
            | '{' initializer_list ',' '}'  { $$ = new InitializerListHolder($2); }
            ;

initializer_list : initializer                      { $$ = new InitializerList(NULL, $1); }
                 | initializer_list ',' initializer { $$ = new InitializerList($1, $3); }
                 ;

//**************************************************************************************
//-------------------------------------- STATEMENTS ------------------------------------
//**************************************************************************************

statement : labeled_statement       { $$ = $1; }
          | compound_statement      { $$ = $1; }
          | expression_statement    { $$ = $1; }
          | selection_statement     { $$ = $1; }
          | iteration_statement     { $$ = $1; }
          | jump_statement          { $$ = $1; }
          ;

labeled_statement : CASE expression ':' statement   { $$ = new CaseBlock($2, $4); }
                  | DEFAULT ':' statement           { $$ = new DefaultCaseBlock($3); }
                  ;

compound_statement : '{' '}'                                        { $$ = new CompoundStatement(NULL, NULL); }
                   | '{' declaration_list '}'                       { $$ = new CompoundStatement($2, NULL); }     
                   | '{' statement_list '}'                         { $$ = new CompoundStatement(NULL, $2); }
                   | '{' declaration_list statement_list '}'        { $$ = new CompoundStatement($2, $3); }
                   ;

declaration_list : declaration                    { $$ = new DeclarationList(NULL, $1); }         
                 | declaration_list declaration   { $$ = new DeclarationList($1, $2); }
                 ;

statement_list : statement                  { $$ = new StatementList(NULL, $1); }
               | statement_list statement   { $$ = new StatementList(reinterpret_cast<StatementList*>($1), $2); }
               ;

expression_statement : ';'              { $$ = new ExpressionStatement(NULL); }
                     | expression ';'   { $$ = new ExpressionStatement($1); }
                     ;

selection_statement : IF '(' expression ')' statement %prec NOELSE      { $$ = new IfStatement($3, $5); }
                    | IF '(' expression ')' statement ELSE statement    { $$ = new IfElseStatement($3, $5, $7); }
                    | SWITCH '(' expression ')' statement               { $$ = new SwitchStatement($3, $5); }
                    ;

iteration_statement : WHILE '(' expression ')' statement                                { $$ = new WhileLoop($3, $5); }
                    | DO statement WHILE '(' expression ')'                             { $$ = new DoWhileLoop($2, $5); }
                    | FOR '(' ';' ';' ')' statement                                     { $$ = new ForLoop(NULL,NULL,NULL,$6); }
                    | FOR '(' expression ';' ';' ')' statement                          { $$ = new ForLoop($3,  NULL,NULL,$7); }
                    | FOR '(' ';' expression ';' ')' statement                          { $$ = new ForLoop(NULL,$4,  NULL,$7); }
                    | FOR '(' ';' ';' expression ')' statement                          { $$ = new ForLoop(NULL,NULL,$5  ,$7); }
                    | FOR '(' expression ';' expression ';' ')' statement               { $$ = new ForLoop($3,  $5,  NULL,$8); }
                    | FOR '(' ';' expression ';' expression ')' statement               { $$ = new ForLoop(NULL,$4,  $6  ,$8); }
                    | FOR '(' expression ';' ';' expression ')' statement               { $$ = new ForLoop($3,  NULL,$6  ,$8); }
                    | FOR '(' expression ';' expression ';' expression ')' statement    { $$ = new ForLoop($3,  $5,  $7  ,$9); }
                    ;

jump_statement : CONTINUE ';'           { $$ = new Continue(); }
               | BREAK ';'              { $$ = new Break(); }
               | RETURN ';'             { $$ = new Return(NULL); }
               | RETURN expression ';'  { $$ = new Return($2); }
               ;

//**************************************************************************************
//------------------------------------- EXPRESSIONS ------------------------------------
//**************************************************************************************

argument_expression_list : expression                                { $$ = new ArgumentExprList(NULL, $1); }
                         | argument_expression_list ',' expression   { $$ = new ArgumentExprList($1, $3); }
                         ;

expression : conditional_expression                         { $$ = $1; }
           | unary_expression '=' expression                { $$ = new Assignment($1, $3); }
           | unary_expression PLUS_EQUAL expression         { $$ = new AddAssignment($1, $3); }
           | unary_expression MINUS_EQUAL expression        { $$ = new SubAssignment($1, $3); }
           | unary_expression TIMES_EQUAL expression        { $$ = new MulAssignment($1, $3); }
           | unary_expression DIVIDE_EQUAL expression       { $$ = new DivAssignment($1, $3); }
           | unary_expression MOD_EQUAL expression          { $$ = new ModAssignment($1, $3); }
           | unary_expression LEFT_SHIFT_EQUAL expression   { $$ = new LeftShiftAssignment($1, $3); }
           | unary_expression RIGHT_SHIFT_EQUAL expression  { $$ = new RightShiftAssignment($1, $3); }
           | unary_expression B_AND_EQUAL expression        { $$ = new BitwiseANDAssignment($1, $3); }
           | unary_expression XOR_EQUAL expression          { $$ = new BitwiseXORAssignment($1, $3); }
           | unary_expression B_OR_EQUAL expression         { $$ = new BitwiseORAssignment($1, $3); }
           ;

conditional_expression : logical_or_expression                                              { $$ = $1; }
                       | logical_or_expression '?' expression ':' conditional_expression    { $$ = new ConditionalOp($1, $3, $5); }
                       ;

logical_or_expression : logical_and_expression                                  { $$ = $1; }
                      | logical_or_expression OR logical_and_expression         { $$ = new LogicalOROp($1, $3); }
                      ;

logical_and_expression : inclusive_or_expression                                { $$ = $1; }
                       | logical_and_expression AND inclusive_or_expression     { $$ = new LogicalANDOp($1, $3); }
                       ;

inclusive_or_expression : exclusive_or_expression                               { $$ = $1; }
                        | inclusive_or_expression '|' exclusive_or_expression   { $$ = new BitwiseInclusiveOROp($1, $3); }
                        ;

exclusive_or_expression : and_expression                                 { $$ = $1; }
                        | exclusive_or_expression '^' and_expression     { $$ = new BitwiseExclusiveOROp($1, $3); }
                        ;

and_expression : equality_expression                        { $$ = $1; }
               | and_expression '&' equality_expression     { $$ = new BitwiseANDOp($1, $3); }
               ;

equality_expression : relational_expression                                     { $$ = $1; }
                    | equality_expression EQUAL_TO relational_expression        { $$ = new EqualToOp($1, $3); }
                    | equality_expression NOT_EQUAL_TO relational_expression    { $$ = new NotEqualToOp($1, $3); }
                    ;

relational_expression : shift_expression                                          { $$ = $1; }
                      | relational_expression '<' shift_expression                { $$ = new LessThanOp($1, $3); }
                      | relational_expression '>' shift_expression                { $$ = new MoreThanOp($1, $3); }
                      | relational_expression LESS_THAN_EQUAL shift_expression    { $$ = new LessThanEqualToOp($1, $3); }
                      | relational_expression MORE_THAN_EQUAL shift_expression    { $$ = new MoreThanEqualToOp($1, $3); }
                      ;

shift_expression : additive_expression                                  { $$ = $1; }
                 | shift_expression LEFT_SHIFT additive_expression      { $$ = new LeftShiftOp($1, $3); }
                 | shift_expression RIGHT_SHIFT additive_expression     { $$ = new RightShiftOp($1, $3); }
                 ;

additive_expression : multiplicative_expression                           { $$ = $1; }
                    | additive_expression '+' multiplicative_expression   { $$ = new AddOp($1, $3); }
                    | additive_expression '-' multiplicative_expression   { $$ = new SubOp($1, $3); }
                    ;

multiplicative_expression : unary_expression                               { $$ = $1; }
                          | multiplicative_expression '*' unary_expression { $$ = new MultiplyOp($1, $3); }
                          | multiplicative_expression '/' unary_expression { $$ = new DivideOp($1, $3); }
                          | multiplicative_expression '%' unary_expression { $$ = new ModOp($1, $3); }
                          ;

unary_expression : postfix_expression                            { $$ = $1;}
                 | PLUSPLUS unary_expression                     { $$ = new PrefixIncOp($2); }
                 | MINUSMINUS unary_expression                   { $$ = new PrefixDecOp($2); }
                 | SIZEOF unary_expression                       { $$ = new SizeOfExpr($2); }
                 | SIZEOF '(' type_name ')'                      { $$ = new SizeOfType($3); }
                 | '&' unary_expression                          { $$ = new ReferenceOp($2); }
                 | '*' unary_expression                          { $$ = new DereferenceOp($2);}
                 | '+' unary_expression                          { $$ = $2; }
                 | '-' unary_expression                          { $$ = new NegationOp($2); }
                 | '~' unary_expression                          { $$ = new InvertOp($2); }
                 | '!' unary_expression                          { $$ = new NotOp($2); }
                 ;

postfix_expression : primary_expression                                    { $$ = $1;}
                   | postfix_expression '[' expression ']'                 { $$ = new PostfixArrIndex($1, $3); }
                   | postfix_expression '(' ')'                            { $$ = new PostfixFuncCall($1, NULL); }
                   | postfix_expression '(' argument_expression_list ')'   { $$ = new PostfixFuncCall($1, $3); }
                   | postfix_expression '.' IDENTIFIER                     { $$ = new PostfixDotOp($1,*$3); }
                   | postfix_expression ARROW IDENTIFIER                   { $$ = new PostfixArrowOp($1,*$3); }
                   | postfix_expression PLUSPLUS                           { $$ = new PostfixIncOp($1); }
                   | postfix_expression MINUSMINUS                         { $$ = new PostfixDecOp($1); }
                   ;

primary_expression : IDENTIFIER                 { $$ = new PrimaryExprIdentifier(*$1); }
                   | NUMBER                     { $$ = new PrimaryExprConstant($1); }
                   | STRING_LITERAL      	    { $$ = new PrimaryExprStrLiteral(*$1); }
                   | '(' expression ')'         { $$ = $2; }
                   ;
%%

AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}

AST* parseAST(char* in) {
    g_root = 0;
    yyin = fopen(in, "r");
    if(yyin) { 
	    yyparse();
    }
    fclose(yyin);
    return g_root;
}
