%{

#include "test.tab.h"
%}




%%

"+" { return ADD;}
"-" { return SUB;}
"*" { return MUL;}
"/" { return DIV; }
"|" { return ABS; }
[0-9]+ { return NUMBER; }
[\n]     {return EOL;}
[ \t] {}
.   {printf("MYSTERY CHAR\n");}

%%

