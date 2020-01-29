%{

    #define YYSTYPE string

    #include "Node.hpp"
    #include "includes.hpp"
    #include "Element.hpp"

    int yylex(void);
    void yyerror(char const*)

%}




%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%



%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(char const* s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}