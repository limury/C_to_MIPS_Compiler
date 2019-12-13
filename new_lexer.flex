* add LIT_CHAR

%option noyywrap

%{
    #include "new_parser.hpp"
%}

%%

auto            { count(); return KEY_AUTO; }
break           { count(); return KEY_BREAK; }
case            { count(); return KEY_CASE; }
char            { count(); return TYPE_CHAR; }
const           { count(); return KEY_CONST; }
continue        { count(); return KEY_CONTINUE; }
default         { count(); return KEY_DEFAULT; }
do              { count(); return KEY_DO; }
double          { count(); return TYPE_DOUBLE; }
else            { count(); return KEY_ELSE; }

enum            { count(); return KEY_ENUM; }
extern          { count(); return KEY_EXTERN; }
float           { count(); return TYPE_FLOAT; }
for             { count(); return KEY_FOR; }
goto            { count(); return KEY_GOTO; }
if              { count(); return KEY_IF; }
int             { count(); return TYPE_INT; }
long            { count(); return KEY_LONG; }
register        { count(); return KEY_REGISTER; }

return          { count(); return KEY_RETURN; }
short           { count(); return KEY_SHORT; }
signed          { count(); return KEY_SIGNED; }
sizeof          { count(); return KEY_SIZEOF; }
static          { count(); return KEY_STATIC; }
struct          { count(); return KEY_STRUCT; }
switch          { count(); return KEY_SWITCH; }
typedef         { count(); return KEY_TYPEDEF; }
union           { count(); return KEY_UNION; }
unsigned        { count(); return KEY_UNSIGNED; }
void            { count(); return TYPE_VOID; }
volatile        { count(); return KEY_VOLATILE; }
while           { count(); return KEY_WHILE; }

"+"             { count(); return OP_PLUS; }
"-"             { count(); return OP_MINUS; }
"*"             { count(); return OP_MULT; }
"/"             { count(); return OP_DIV; }
"%"             { count(); return OP_MODULO; }
"<<"            { count(); return OP_LSHIFT; }
">>"            { count(); return OP_RSHIFT; }

"<"             { count(); return OP_LT; }
">"             { count(); return OP_GT; }
"<="            { count(); return OP_LTEQ; }
">="            { count(); return OP_GTEQ; }
"=="            { count(); return OP_EQEQ; }
"!="            { count(); return OP_NE; }
"&"             { count(); return OP_BIT_AND; }
"&&"            { count(); return OP_AND; }
"|"             { count(); return OP_BIT_OR; }
"||"            { count(); return OP_OR; }

"^"             { count(); return OP_XOR; }
"="             { count(); return OP_EQ; }
"+="            { count(); return OP_PLUSEQ; }
"-="            { count(); return OP_MINUSEQ; }
"*="            { count(); return OP_MULTEQ; }
"/="            { count(); return OP_DIVEQ; }
"%="            { count(); return OP_MODEQ; }
"&="            { count(); return OP_ANDEQ; }
"|="            { count(); return OP_OREQ; }
"^="            { count(); return OP_XOREQ; }

"<<="           { count(); return OP_LSHIFTEQ; }
">>="           { count(); return OP_RSHIFTEQ; }
"."             { count(); return OP_DOT; }
"->"            { count(); return OP_ARROW; }
","             { count(); return OP_COMMA; }
":"             { count(); return OP_COLON; }
";"             { count(); return OP_SEMICOLON; }
"?"             { count(); return OP_QUESTION; }

"("             { count(); return OP_LPARENTHESES; }
")"             { count(); return OP_RPARENTHESES; }
"["             { count(); return OP_LBRACKET; }
"]"             { count(); return OP_RBRACKET; }
"{"             { count(); return OP_LBRACE; }
"}"             { count(); return OP_RBRACE; }

"!"             { count(); return OP_NOT; }
"~"             { count(); return OP_BIT_NOT; }
"++"            { count(); return OP_PLUS_PLUS; }
"--"            { count(); return OP_MINUS_MINUS; }
"..."           { count(); return OP_ELLIPSIS; }

\"(\\.|[^"\\])*\"       { count(); return LIT_STRING; }
[0-9]+.[0-9]+           { count(); return LIT_DOUBLE; }
[0-9]+                  { count(); return LIT_INT; }
[a-zA-Z]\w*             { count(); return IDENTIFIER; }

%%

void yyerror (char const *s){
    std::cout << "parse error: " << yytext << std::endl;
    exit(1);
}