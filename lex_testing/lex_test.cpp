#include <iostream>
#include <string>

#include "lex_test.hpp"

TokenValue yylval;

std::string multiStr(int num, const std::string& str) {
    if (num == 0)
        return "";
    else
        return multiStr(num-1, str) + str;
}

int main() {
    yytokentype token;
    int indent = 0;
    while((token = (yytokentype)yylex())) {
        if (token == '}')
            indent--;
        std::string tokenName = "";
        if (tokenMap.find(token) != tokenMap.end())
            tokenName = tokenMap.at(token) + ": ";
        std::cout << multiStr(indent,"\t") << tokenName;
        if (token == NUMBER)
            std::cout << yylval.number << std::endl;
        else {
            std::cout << *(yylval.string) << std::endl;
            delete yylval.string;
        }
        if (token == '{')
            indent++;
    }
}