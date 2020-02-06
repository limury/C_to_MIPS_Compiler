#include "../include/Node.hpp"

void printTree(NodePtr root, int depth);

int main(){

    int alpha = 1;
    std::cout << alpha << std::endl;
    alpha++;
//    std::cin >> alpha;
    std::cout << "alpha is " << alpha << std::endl;
    const NodePtr ast = parseAST();
    std::cout << "Printing tree: " << ast << std::endl;
    printTree(ast, 0);
}


void printTree( NodePtr root, int depth ){
    for (int i = 0; i < depth; i++){
        std::cout << "\t";
    }
    if ( root->branches.size() != 0 ){
        std::cout << root->type << std::endl;
        for (int i = 0; i < root->branches.size(); i++){
            printTree( root->branches.at(i), depth+1 );
        }
    }
    else {
        std::cout << "Type: " << root->type << ". Value: " << *root->value << std::endl;
    }
}