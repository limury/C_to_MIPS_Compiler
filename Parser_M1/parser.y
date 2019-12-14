%token              STRING_LIT INT_LIT
%token              PTR_

%%


argument_expr:              IDENTIFIER
|                           CONSTANT
|                           STRING_LIT
|                           '(' expr ')';

expression:                 assignment_expr
|                           expression ',' assignment_expr;

assignment_expr:            conditional_expr