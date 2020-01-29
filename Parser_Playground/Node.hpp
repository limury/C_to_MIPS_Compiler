#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

enum TokenType{ ADD, SUB, MUL, DIV, ABS, NUMBER, EOL };
union TokenValue{ int numberVal; };

extern TokenValue yylval;
extern int yylex();

int main(){
    
}


#endif