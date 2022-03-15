%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "lex_test.hpp"
#include "LexContext.hpp"

LexContext context;

int token(int);
int tokenTYPE(int type);
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+

%%

("/*"[^"*/"]*"*/")|("//".*) {}
[ \t\n\r]       {}
"#".*           {}

\"([^\"]|"\\\"")*\" { 
                        std::string temp = std::string(yytext);
                        temp = temp.substr(1, temp.size()-2);
                        yylval.string = new std::string(temp);
                        return STRING_LITERAL;
                    }

\'([^\']|"\\\'")\'  {
                        yylval.number = yytext[1];
                        return NUMBER;
                    }

"*"             { return token('*'); }
"+"             { return token('+'); }
"/"             { return token('/'); }
"-"             { return token('-'); }
"%"             { return token('%'); }
"++"            { return token(PLUSPLUS); }
"--"            { return token(MINUSMINUS); }

"=="            { return token(EQUAL_TO); }
"<"             { return token('<'); }
">"             { return token('>'); }
"!="            { return token(NOT_EQUAL_TO); }
"<="            { return token(LESS_THAN_EQUAL); }
">="            { return token(MORE_THAN_EQUAL); }

"&&"            { return token(AND); }
"||"            { return token(OR); }
"!"             { return token('!'); }

"&"             { return token('&'); }
"|"             { return token('|'); }
"\^"            { return token('^'); } 
"~"             { return token('~'); }
"<<"            { return token(LEFT_SHIFT); }
">>"            { return token(RIGHT_SHIFT); }

"="             {
                    context.declarationActive(false);
                    context.enumActive(false);
                    context.endTopLevel();
                    return token('=');
                }

"+="            { return token(PLUS_EQUAL); }
"-="            { return token(MINUS_EQUAL); }
"*="            { return token(TIMES_EQUAL); }
"/="            { return token(DIVIDE_EQUAL); }
"%="            { return token(MOD_EQUAL); }
"<<="           { return token(LEFT_SHIFT_EQUAL); }
">>="           { return token(RIGHT_SHIFT_EQUAL); }
"&="            { return token(B_AND_EQUAL); }
"\^="           { return token(XOR_EQUAL); }
"|="            { return token(B_OR_EQUAL); }

"?"             { return token('?'); }
":"             { return token(':'); }
","             { return token(','); }
"."             { return token('.'); }
"->"            { return token(ARROW); }
"\""            { return token('\"'); }

";"             { 
                    if (context.typeDefActive()) {
                        context.addTypeDef(context.currentName);
                        context.typeDefActive(false);
                    }
                    context.endTopLevel();
                    context.declarationActive(false);
                    context.enumActive(false);
                    return token(';'); 
                }

"("             { return token('('); }
")"             { return token(')'); }
"["             { return token('['); }
"]"             { return token(']'); }

"{"             {
                    context.ignoreIdentifier(false);
                    if (context.enumActive()) 
                        context.storeEnumVals(true);
                    context.addScope();
                    return token('{');
                }
"}"             {
                    context.subScope();
                    context.enumActive(false);
                    context.storeEnumVals(false);
                    return token('}');
                }

"auto"          { return tokenTYPE(AUTO); }
"break"         { return token(BREAK); }
"case"          { return token(CASE); }
"char"          { return tokenTYPE(CHAR); }
"const"         { return tokenTYPE(CONST); }
"continue"      { return token(CONTINUE); }
"default"       { return token(DEFAULT); }
"do"            { return token(DO); }
"double"        { return tokenTYPE(DOUBLE); }
"else"          { return token(ELSE); }
"extern"        { return tokenTYPE(EXTERN); }
"float"         { return tokenTYPE(FLOAT); }
"for"           { return token(FOR); }
"goto"          { return token(GOTO); }
"if"            { return token(IF); }
"int"           { return tokenTYPE(INT); }
"long"          { return tokenTYPE(LONG); }
"register"      { return tokenTYPE(REGISTER); }
"return"        { return token(RETURN); }
"short"         { return tokenTYPE(SHORT); }
"signed"        { return tokenTYPE(SIGNED); }
"sizeof"        { return token(SIZEOF); }
"static"        { return tokenTYPE(STATIC); }
"switch"        { return token(SWITCH); }

"typedef"       { 
                    context.typeDefActive(true);
                    return token(TYPEDEF); 
                }

"unsigned"      { return tokenTYPE(UNSIGNED); }
"void"          { return tokenTYPE(VOID); }
"volatile"      { return tokenTYPE(VOLATILE); }
"while"         { return token(WHILE); }

"struct"                {   
                            context.setTopLevel();
                            context.ignoreIdentifier(true);
                            return tokenTYPE(STRUCT); 
                        }

"enum"                  {   
                            context.setTopLevel();
                            context.ignoreIdentifier(true);
                            context.enumActive(true);
                            return tokenTYPE(ENUM); 
                        }

"union"                 {   
                            context.ignoreIdentifier(true);
                            return tokenTYPE(UNION); 
                        }
 
[a-zA-Z_][0-9a-zA-Z_]*  {   
                            std::string temp = std::string(yytext);
                            if (context.declarationActive() && !context.ignoreIdentifier()) {
                                context.declarationActive(false);
                                context.findAndDestroyTD(temp);
                                context.findAndDestroyE(temp);
                                if (context.typeDefActive())
                                    context.currentName = temp;
                                return token(IDENTIFIER);
                            }

                            if (context.storeEnumVals()) {
                                context.addEnumVal(temp);
                                return token(IDENTIFIER);
                            }

                            if (context.ignoreIdentifier())
                                context.ignoreIdentifier(false);

                            if (context.typeDefActive())
                                context.currentName = temp;

                            if (context.typeDefed(temp))
                                return tokenTYPE(TYPEDEF_T);
                            else if (context.enummed(temp))
                                return token(ENUM_VAL);
                            else
                                return token(IDENTIFIER);
                        }

0[xX]{H}+   	{ yylval.number = std::stoi(yytext, 0, 16); return NUMBER; }
0{D}+   		{ yylval.number = std::stoi(yytext, 0, 8); return NUMBER; }
{D}+    		{ yylval.number = std::stoi(yytext, 0, 10); return NUMBER; }

{D}+{E} 		{ yylval.number = std::stod(yytext, 0); return NUMBER; }
{D}*"."{D}+({E})?	{ yylval.number = std::stod(yytext, 0); return NUMBER; }
{D}+"."{D}*({E})?	{ yylval.number = std::stod(yytext, 0); return NUMBER; }

.               { fprintf(stderr, "Invalid character: %s\n", yytext); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}

int token(int type) {
    yylval.string = new std::string(yytext);		
	return type;
}

int tokenTYPE(int type) {
    yylval.string = new std::string(yytext);
    if (!context.typeDefActive())
        context.declarationActive(true);
    return type;
}