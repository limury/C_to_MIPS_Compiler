
%option noyywrap


D               [0-9]
L               [a-zA-Z_]
H               [a-fA-F0-9]
E               [Ee][+-]?{D}+
FS              (f|F|l|L)
IS              (f|F|l|L)*


%{

extern "C" int fileno(FILE *stream);

#include <stdio.h>
#include "parser.tab.hpp"
#include "../include/Node.hpp"


extern void yyerror(const char *);  /* prints grammar violation message */

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) T_IDENTIFIER /* with no symbol table, fake it */
#define YYSTYPE std::string*

static void comment(void);
static int check_type(void);
%}

%%
"/*"                                    { /*comment();*/ }
"//".*                                    { /* consume //-comment */ }

"auto"					{ return(T_AUTO); }
"break"					{ return(T_BREAK); }
"case"					{ return(T_CASE); }
"char"					{ return(T_CHAR); }
"const"					{ return(T_CONST); }
"continue"				{ return(T_CONTINUE); }
"default"				{ return(T_DEFAULT); }
"do"					{ return(T_DO); }
"double"				{ return(T_DOUBLE); }
"else"					{ return(T_ELSE); }
"enum"					{ return(T_ENUM); }
"extern"				{ return(T_EXTERN); }
"float"					{ return(T_FLOAT); }
"for"					{ return(T_FOR); }
"goto"					{ return(T_GOTO); }
"if"					{ return(T_IF); }
"int"					{ return(T_INT); }
"long"					{ return(T_LONG); }
"register"				{ return(T_REGISTER); }
"return"				{ return(T_RETURN); }
"short"					{ return(T_SHORT); }
"signed"				{ return(T_SIGNED); }
"sizeof"				{ return(T_SIZEOF); }
"static"				{ return(T_STATIC); }
"struct"				{ return(T_STRUCT); }
"switch"				{ return(T_SWITCH); }
"typedef"				{ return(T_TYPEDEF); }
"union"					{ return(T_VOLATILE); }
"unsigned"				{ return(T_UNSIGNED); }
"void"					{ return(T_VOID); }
"volatile"				{ return(T_VOLATILE); }
"while"					{ return(T_WHILE); }


[a-zA-Z_][a-zA-Z0-9_]*					{ yylval.string = new std::string(yytext); return check_type(); }

{L}({L}|{D})*		{ return(check_type()); }

0[xX]{H}+{IS}?		{ return(CONSTANT); }
0{D}+{IS}?		{ return(CONSTANT); }
{D}+{IS}?		{ return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ return(CONSTANT); }

{D}+{E}{FS}?		{ return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ yylval.string = new std::string(yytext); return T_STRING_LITERAL; }


"..."					{ return T_ELLIPSIS; }
">>="					{ return T_RIGHT_ASSIGN; }
"<<="					{ return T_LEFT_ASSIGN; }
"+="					{ return T_ADD_ASSIGN; }
"-="					{ return T_SUB_ASSIGN; }
"*="					{ return T_MUL_ASSIGN; }
"/="					{ return T_DIV_ASSIGN; }
"%="					{ return T_MOD_ASSIGN; }
"&="					{ return T_AND_ASSIGN; }
"^="					{ return T_XOR_ASSIGN; }
"|="					{ return T_OR_ASSIGN; }
">>"					{ return T_RIGHT_OP; }
"<<"					{ return T_LEFT_OP; }
"++"					{ return T_INC_OP; }
"--"					{ return T_DEC_OP; }
"->"					{ return T_PTR_OP; }
"&&"					{ return T_AND_OP; }
"||"					{ return T_OR_OP; }
"<="					{ return T_LE_OP; }
">="					{ return T_GE_OP; }
"=="					{ return T_EQ_OP; }
"!="					{ return T_NE_OP; }
";"					{ return ';'; }
("{"|"<%")				{ return '{'; }
("}"|"%>")				{ return '}'; }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."					{ return '.'; }
"&"					{ return '&'; }
"!"					{ return '!'; }
"~"					{ return '~'; }
"-"					{ return '-'; }
"+"					{ return '+'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"<"					{ return '<'; }
">"					{ return '>'; }
"^"					{ return '^'; }
"|"					{ return '|'; }
"?"					{ return '?'; }

[ \t\v\n\f]					{ /* whitespace separates tokens */ }
.					{ /* discard bad characters */ }

%%



void yyerror (char const *s){
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}




int check_type(void)
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return TYPE_NAME;
*
*	return IDENTIFIER;
*/

/*
*	it actually will only return IDENTIFIER
*/

	return IDENTIFIER;
}