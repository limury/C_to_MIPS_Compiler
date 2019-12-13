%option noyywrap

%{
extern "C" int fileno(FILE *stream);
void count();

#include "parser.hpp"
%}

DIGIT [0-9]
HEXDIGIT [0-9A-Fa-f]


%%

int                 return TYPE_INT;
[a-zA-Z]\w*         return IDENTIFIER;
"("                 return OP_LPARENTHESES;
")"                 return OP_RPARENTHESES;
"{"                 return OP_LBRACE;
"}"                 return OP_RBRACE;
return              return RETURN;
[0-9]+              return LIT_INTEGER;

auto                return AUTO;
break               return BREAK;
case                return CASE;
char                return TYPE_CHAR;
const               return CONST;
continue            return CONTINUE;
default             return DEFAULT;
do                  return DO;
double              return TYPE_DOUBLE;
else                return ELSE;
enum                return ENUM;
extern              return EXTERN;
float               return TYPE_FLOAT;
for                 return FOR;
goto                return GOTO;
if                  return IF;
int                 return INT;
long                return LONG;
register            return REGISTER;
return              return RETURN;
short               return SHORT;
signed              return SIGNED;
sizeof              return SIZEOF;
static              return STATIC;
struct              return STRUCT;
switch              return SWITCH;
typedef             return TYPEDEF;
union               return UNION;
unsigned            return UNSIGNED;
void                return TYPE_VOID;
volatile            return VOLATILE;
while               return WHILE;

"+"                 return OP_PLUS;
"-"                 return OP_MINUS;
"*"                 return OP_MULTIPLY;
"/"                 return OP_DIVIDE;
"%"                 return OP_MOD;
"++"                return OP_PLUS_PLUS;
"--"                return OP_MINUS_MINUS;

"<"                 return OP_LT;
">"                 return OP_GT;
"<="                return OP_LTE;
">="                return OP_GTE;
"=="                return OP_EQ;
"!="                return OP_NE;

"&&"                return OP_AND;
"||"                return OP_OR;
"!"                 return OP_NOT;

"&"                 return OP_AND_BIT;
"|"                 return OP_OR_BIT;
"^"                 return OP_XOR_BIT;
"~"                 return OP_NOT_BIT;
"<<"                return OP_LSHIFT;
">>"                return OP_RSHIFT;

"="                 return OP_EQUALS;
"+="                return OP_PLUS_EQ;
"-="                return OP_MINUS_EQ;
"*="                return OP_MULT_EQ;
"/="                return OP_DIV_EQ;
"%="                return OP_MODULO_EQ;
"<<="               return OP_LSHIFT_EQ;
">>="               return OP_RSHIFT_EQ;
"&="                return OP_AND_EQ;
"|="                return OP_OR_EQ;
"^="                return OP_XOR_EQ;

"."                 return OP_DOT;
"->"                return OP_ARROW;
","                 return OP_COMMA;
":"                 return OP_COLON
";"                 return OP_SEMICOLON;
"?"                 return OP_QUESTION;
"["                 return OP_LBRACKET;
"]"                 return OP_RBRACKET;

[0-9]+\.[0-9]+      return LIT_DOUBLE;
\"(\\.|[^"\\])*\"   return LIT_STRING;


%%





int column = 0;
int row = 0;
void count()
{
	for (size_t i = 0; i < strlen(yytext); ++i)
  {
		if (yytext[i] == '\n') { column = 0; row++; }
		else if (yytext[i] == '\t') { column += 8 - (column % 8); }
		else { column++; }
  }
}

void yyerror (char const *s)
{
  std::cout << "parse error: " << yytext << std::endl;
  std::cout << "line " << (row + 1) << ", column " << (column + 1 - strlen(yytext)) << std::endl;
  exit(1);
}
