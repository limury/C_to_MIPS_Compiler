#include "../ast_structure/Node.hpp"

Node::Node(){
    std::vector<NodePtr> tmp;
    branches = tmp;
}

void Node::addNode (NodePtr other){
    branches.push_back(other);
}