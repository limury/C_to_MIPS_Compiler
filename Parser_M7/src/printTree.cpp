#include "../include/Node.hpp"

void printTree(NodePtr root, int depth);

int main(){

    const NodePtr ast = parseAST();
    std::cout << "Printing tree: " << ast << std::endl << std::endl << std::endl;
    printTree(ast, 0);
}


void printTree( NodePtr root, int depth ){
    for (int i = 0; i < depth; i++){
        std::cout << "    ";
    }
    std::cout << root->getValue();
    if ( root->branches.size() != 0 ){
        for (int i = 0; i < root->branches.size(); i++){
            printTree( root->branches.at(i), depth+1 );
        }
    }
}