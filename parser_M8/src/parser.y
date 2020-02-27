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
    RootPtr node;
    yytokentype token;
    std::string* string;
	unaryOperator* op;
}


%type<node> start primary_expression postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression assignment_operator expression constant_expression declaration declaration_specifiers init_declarator_list init_declarator storage_class_specifier type_specifier struct_specifier struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier enumerator_list enumerator type_qualifier declarator direct_declarator pointer type_qualifier_list parameter_type_list parameter_list parameter_declaration identifier_list type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition
%type<unaryOperator> unary_operator

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
	: T_IDENTIFIER            { $$ = new PrimaryExpression(IDENTIFIER, *$1); }
	| T_CONSTANT              { $$ = new PrimaryExpression(CONSTANT, *$1); }
	| T_STRING_LITERAL        { $$ = new PrimaryExpression(STRING_LIT, *$1); }
	| '(' expression ')'      { $$ = $2; }
	;

postfix_expression
	: primary_expression    
	| postfix_expression '[' expression ']'     				{ $$ = new ArrayPostfixExpression($1, $3); }
	| postfix_expression '(' ')'        						{ $$ = new FunctionPostfixExpression($1, NULL); }
	| postfix_expression '(' argument_expression_list ')'       { $$ = new FunctionPostfixExpression($1, $3); }
	| postfix_expression '.' T_IDENTIFIER         				{ $$ = new DotPostfixExpression($1, *$3); }
	| postfix_expression T_PTR_OP T_IDENTIFIER      			{ $$ = new ArrowPostfixExpression($1, *$3); }
	| postfix_expression T_INC_OP         						{ $$ = new IncrementPostfixExpression($1); }
	| postfix_expression T_DEC_OP         						{ $$ = new DecrementPostfixExpression($1); }
	;

argument_expression_list
	: assignment_expression             					{ $$ = new ArgumentExpressionList($1); }
	| argument_expression_list ',' assignment_expression    { $$ = new ArgumentExpressionList($1, $3); }
	;

unary_expression
	: postfix_expression
	| T_ADD cast_expression    				{ $$ = $2}
	| T_INC_OP unary_expression           	{ $$ = new PreincrementUnaryExpression($2);}
	| T_DEC_OP unary_expression           	{ $$ = new PredecrementUnaryExpression;}
	| unary_operator cast_expression    	{ $$ = new UnaryOperatorExpression(*$1, $2); }
	| T_SIZEOF unary_expression           	{ $$ = new SizeofUnaryExpression($2); }
	| T_SIZEOF '(' type_name ')'          	{ $$ = new SizeofTypeUnaryExpression($2); }
	;

unary_operator
	: '&'                               { $$ = new unaryOperator(REFERENCE); }
	| '*'                               { $$ = new unaryOperator(DEREFERENCE); }
	| T_SUB                             { $$ = new unaryOperator(MINUS); }
	| '~'                               { $$ = new unaryOperator(BITWISE_NOT); }
	| '!'                              	{ $$ = new unaryOperator(LOGICAL_NOT); }
	;

cast_expression // ?
	: unary_expression
	| '(' type_name ')' cast_expression         { $$ = new Node( cast_expression, NodeVec{  new Operator(L_PARENTHESES), $2, new Operator(R_PARENTHESES), $4  } ); }
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression     { $$ = new MultiplicationExpression($1, $3); }
	| multiplicative_expression '/' cast_expression     { $$ = new DivisionExpression($1, $3); }
	| multiplicative_expression '%' cast_expression     { $$ = new ModulusExpression($1, $3); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression T_ADD multiplicative_expression     { $$ = new AdditionExpression($1, $3); }
	| additive_expression T_SUB multiplicative_expression     { $$ = new SubtractionExpression($1, $3); }
	;

shift_expression
	: additive_expression
	| shift_expression T_LEFT_OP additive_expression      { $$ = new LeftShiftExpression($1, $3); }
	| shift_expression T_RIGHT_OP additive_expression     { $$ = new RightShiftExpression($1, $3); }
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression        { $$ = new LessThanExpression($1, $3); }
	| relational_expression '>' shift_expression        { $$ = new GreaterThanExpression($1, $3); }
	| relational_expression T_LE_OP shift_expression      { $$ = new LessEqualExpression($1, $3); }
	| relational_expression T_GE_OP shift_expression      { $$ = new GreaterEqualExpression($1, $3); }
	;

equality_expression
	: relational_expression
	| equality_expression T_EQ_OP relational_expression   { $$ = new EqualityExpression($1, $3); }
	| equality_expression T_NE_OP relational_expression   { $$ = new InequalityExpression($1, $3); }
	;

and_expression
	: equality_expression                               
	| and_expression '&' equality_expression            { $$ = new AndBitwiseExpression($1, $3); }
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression        { $$ = new XorBitwiseExpression($1, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression   { $$ = new OrBitwiseExpression($1, $3); }
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression T_AND_OP inclusive_or_expression { $$ = new AndLogicalExpression($1, $3); }
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression T_OR_OP logical_and_expression    { $$ = new OrLogicalExpression($1, $3); }
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression   { $$ = new ConditionalExpression($1, $3, $5); }
	;

assignment_expression
	: conditional_expression
	| unary_expression '=' assignment_expression                          	{ $$ = new EqualAssignmentExpression($1, $3); }
	| unary_expression T_MUL_ASSIGN assignment_expression                   { $$ = new MultAssignmentExpression($1, $3); }
	| unary_expression T_DIV_ASSIGN assignment_expression                   { $$ = new DivAssignmentExpression($1, $3); }
	| unary_expression T_MOD_ASSIGN assignment_expression                   { $$ = new ModAssignmentExpression($1, $3); }
	| unary_expression T_ADD_ASSIGN assignment_expression                   { $$ = new AddAssignmentExpression($1, $3); }
	| unary_expression T_SUB_ASSIGN assignment_expression                   { $$ = new SubAssignmentExpression($1, $3); }
	| unary_expression T_LEFT_ASSIGN assignment_expression                  { $$ = new LeftAssignmentExpression($1, $3); }
	| unary_expression T_RIGHT_ASSIGN assignment_expression                 { $$ = new RightAssignmentExpression($1, $3); }
	| unary_expression T_AND_ASSIGN assignment_expression                   { $$ = new AndAssignmentExpression($1, $3); }
	| unary_expression T_XOR_ASSIGN assignment_expression                   { $$ = new XorAssignmentExpression($1, $3); }
	| unary_expression T_OR_ASSIGN assignment_expression                    { $$ = new OrAssignmentExpression($1, $3); }
	;

expression
	: assignment_expression						{ $$ = new ExpressionList($1); }
	| expression ',' assignment_expression      { $$ = new ExpressionList($1, $3); }
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'                        
	| declaration_specifiers init_declarator_list ';'   { $$ = new Declaration($1, $2); }
	;

declaration_specifiers // ? storage class specifier only typedef?
	: storage_class_specifier                           { $$ = new TypedefDeclarationSpecifier(NULL); }
	| storage_class_specifier declaration_specifiers    { $$ = new TypedefDeclarationSpecifier($2); }
	| type_specifier									
	| type_specifier declaration_specifiers             { $$ = new SpecDeclarationSpecifier($2, $1); }
	;

init_declarator_list
	: init_declarator									{ $$ = new InitDeclaratorList($1); }
	| init_declarator_list ',' init_declarator          { $$ = new InitDeclaratorList($1, $3); }
	;

init_declarator
	: declarator
	| declarator '=' initializer            { $$ = new InitDeclarator($1, $3); }
	;

storage_class_specifier // ?
	: T_TYPEDEF                       { $$ = opGen(TYPEDEF); }
	| T_EXTERN                        { $$ = opGen(EXTERN); }
	| T_STATIC                        { $$ = opGen(STATIC); }
	| T_AUTO                          { $$ = opGen(AUTO); }
	| T_REGISTER                      { $$ = opGen(REGISTER); }
	;

type_specifier
	: T_VOID                          { $$ = PrimitiveType(VOID); }
	| T_CHAR                          { $$ = PrimitiveType(CHAR); }
	| T_SHORT                         { $$ = PrimitiveType(SHORT); }
	| T_INT                           { $$ = PrimitiveType(INT); }
	| T_LONG                          { $$ = PrimitiveType(LONG); }
	| T_FLOAT                         { $$ = PrimitiveType(FLOAT); }
	| T_DOUBLE                        { $$ = PrimitiveType(DOUBLE); }
	| T_SIGNED                        { $$ = PrimitiveType(SIGNED); }
	| T_UNSIGNED                      { $$ = PrimitiveType(UNSIGNED); }
	| struct_specifier     
	| enum_specifier
	| T_TYPE_NAME                     { $$ = TypedefType($1); }
	;

struct_specifier
	: T_STRUCT T_IDENTIFIER '{' struct_declaration_list '}'    	{ $$ = new StructSpecifier(*$2, $4); }
	| T_STRUCT '{' struct_declaration_list '}'       			{ $$ = new StructSpecifier("", $3); }
	| T_STRUCT T_IDENTIFIER            							{ $$ = new StructSpecifier(*$2, NULL); }
	;

struct_declaration_list
	: struct_declaration                            { $$ = new StructDeclarationList($1); }
	| struct_declaration_list struct_declaration    { $$ = new StructDeclarationList($1, $2); }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'   { $$ = new StructDeclaration($1, $2); }
	;

specifier_qualifier_list // ?
	: type_specifier specifier_qualifier_list       { $$ = new Node( specifier_qualifier_list, NodeVec{ $1, $2 } ); }
	| type_specifier
	;

struct_declarator_list
	: struct_declarator								{ $$ = new StructDeclaratorList($1); }
	| struct_declarator_list ',' struct_declarator  { $$ = new StructDeclaratorList($1, $3); }
	;

struct_declarator
	: declarator	
	| ':' constant_expression               		{ $$ = new StructDeclarator(NULL, $2); }
	| declarator ':' constant_expression    		{ $$ = new StructDeclarator($1, $3); }
	;

enum_specifier
	: T_ENUM '{' enumerator_list '}'              	{ $$ = new EnumeratorSpecifier("", $3); }
	| T_ENUM T_IDENTIFIER '{' enumerator_list '}'   { $$ = new EnumeratorSpecifier(*$2, $4); }
	| T_ENUM T_IDENTIFIER                           { $$ = new EnumeratorSpecifier(*$2, NULL); }
	;

enumerator_list
	: enumerator									{ $$ = new EnumeratorList($1); }
	| enumerator_list ',' enumerator            	{ $$ = new EnumeratorList($1, $3); }
	;

enumerator
	: T_IDENTIFIER                					{ $$ = new Enumerator($1, NULL); }
	| T_IDENTIFIER '=' constant_expression      	{ $$ = new Enumerator($1, $3); }
	;

declarator
	: pointer direct_declarator         { $$ = new Declarator($1, $2); }
	| direct_declarator					
	;

direct_declarator
	: T_IDENTIFIER                        				{ $$ = new IdentifierDirectDeclarator(*$1); }
	| '(' declarator ')'                                { $$ = $2; }
	| direct_declarator '[' constant_expression ']'     { $$ = new ArrayDirectDeclarator($1, $3); }
	| direct_declarator '[' ']'                         { $$ = new ArrayDirectDeclarator($1, NULL); }
	| direct_declarator '(' parameter_type_list ')'     { $$ = new FunctionDirectDeclarator( direct_declarator, NodeVec{ $1, opGen(L_PARENTHESES), $3, opGen(R_PARENTHESES) } ); }
	| direct_declarator '(' ')'                         { $$ = new FunctionDirectDeclarator( direct_declarator, NodeVec{ $1, opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
	;

pointer // ? really confused to how these pointer things work...
	: '*'                                   { $$ = new Pointer(NULL) }       
	| '*' pointer                           { $$ = new Pointer($2, false) }    
	;

parameter_type_list // ?
	: parameter_list
	| parameter_list ',' T_ELLIPSIS           { $$ = new Node( parameter_type_list, NodeVec{ $1, opGen(COMMA), opGen(ELLIPSIS) } ); }
	;

parameter_list
	: parameter_declaration							{ $$ = new ParameterList( $1 ); }
	| parameter_list ',' parameter_declaration      { $$ = new ParameterList( $1, $3 ); }
	;

parameter_declaration
	: declaration_specifiers declarator             { $$ = new ParameterDeclaration( $1, $2, NULL ); }
	| declaration_specifiers abstract_declarator    { $$ = new ParameterDeclaration( $1, NULL, $2 ); }
	| declaration_specifiers						{ $$ = new ParameterDeclaration( $1, NULL, NULL ); }
	;

identifier_list  // ??
	: T_IDENTIFIER                            { $$ = new Node( IDENTIFIER, $1 ); }
	| identifier_list ',' T_IDENTIFIER        { $$ = new Node( identifier_list, NodeVec{ $1, opGen(COMMA), new Node(IDENTIFIER, $3) } ); }
	;

type_name
	: specifier_qualifier_list						{ $$ = new TypeName($1, NULL); }
	| specifier_qualifier_list abstract_declarator  { $$ = new TypeName($1, $2); }
	;

abstract_declarator
	: pointer									{ $$ = new AbstractDeclarator($1, NULL); }
	| direct_abstract_declarator				{ $$ = new AbstractDeclarator(NULL, $1); }
	| pointer direct_abstract_declarator        { $$ = new AbstractDeclarator($1, $2); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'                   { $$ = $2; }
	| '[' ']'                                       				{ $$ = new ArrayDirectAbstractDeclarator(NULL, NULL); }
	| '[' constant_expression ']'                   				{ $$ = new ArrayDirectAbstractDeclarator(NULL, $2); }
	| direct_abstract_declarator '[' ']'            				{ $$ = new ArrayDirectAbstractDeclarator($1, NULL); }
	| direct_abstract_declarator '[' constant_expression ']'        { $$ = new ArrayDirectAbstractDeclarator($1, $3); }
	| '(' ')'                                       				{ $$ = new FunctionDirectAbstractDeclarator(NULL, NULL); }
	| '(' parameter_type_list ')'                   				{ $$ = new FunctionDirectAbstractDeclarator(NULL, $2); }
	| direct_abstract_declarator '(' ')'            				{ $$ = new FunctionDirectAbstractDeclarator($1, NULL); }
	| direct_abstract_declarator '(' parameter_type_list ')'        { $$ = new FunctionDirectAbstractDeclarator($1, $3); }
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'              { $$ = new Initializer($2); }
	| '{' initializer_list ',' '}'          { $$ = new Initializer($2); }
	;

initializer_list
	: initializer							{ $$ = new InitializerList($1); }
	| initializer_list ',' initializer      { $$ = new InitializerList($1, $3); }
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement // ?
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
	: declaration					{ $$ = new DeclarationList($1); }
	| declaration_list declaration  { $$ = new DeclarationList($1, $2); }
	;

statement_list
	: statement						{ $$ = new StatementList($1); }
	| statement_list statement      { $$ = new StatementList($1, $2); }
	;

expression_statement
	: ';'       					{ $$ = ExpressionStatement(NULL); }
	| expression ';'                { $$ = ExpressionStatement($1); }
	;

selection_statement
	: T_IF '(' expression ')' statement                   	{ $$ = new IfSelectStatement($3, $5); }
	| T_IF '(' expression ')' statement T_ELSE statement    { $$ = new IfElseSelectStatement($3, $5, $7); }
	| T_SWITCH '(' expression ')' statement           		{ $$ = new SwitchSelectStatement($3, $5); }
	;

iteration_statement  // ?
	: T_WHILE '(' expression ')' statement            { $$ = new WhileIterationStatement($3, $5); }
	| T_DO statement T_WHILE '(' expression ')' ';'     { $$ = new DoWhileIterationStatement($5, $2); }
	| T_FOR '(' expression_statement expression_statement ')' statement   			  { $$ = new ForIterationStatement($3, $4, NULL, $6); }
	| T_FOR '(' expression_statement expression_statement expression ')' statement    { $$ = new ForIterationStatement($3, $4, $5, $7); }
	;

jump_statement
	: T_CONTINUE ';'              { $$ = new ContinueJumpStatement(); }
	| T_BREAK ';'                 { $$ = new BreakJumpStatement(); }
	| T_RETURN ';'                { $$ = new ReturnJumpStatement(NULL); }
	| T_RETURN expression ';'     { $$ = new ReturnJumpStatement($2); }
	;

start
    : translation_unit 						{ root = $1; }

translation_unit
	: external_declaration         				{ $$ = new ExternalDeclarationList($1); }
	| translation_unit external_declaration     { $$ = new ExternalDeclarationList($1, $2); }
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator compound_statement      { $$ = new FunctionDefinition($1, $2, $3); }
	| declarator compound_statement                				{ $$ = new FunctionDefinition(NULL, $1, $2); }
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
