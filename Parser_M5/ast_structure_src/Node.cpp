#include "../ast_structure/Node.hpp"

Node::Node(){
    std::vector<TranslationUnitPtr> tmp;
    branches = tmp;
}

void Node::addNode (TranslationUnitPtr other){
    branches.push_back(other);
}