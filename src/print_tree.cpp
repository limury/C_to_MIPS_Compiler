#include "ast.hpp"
#include <vector>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    AST* ast = parseAST();

    std::ostream& os = std::cout;
    ast->print(os,0);

    return 0;
}