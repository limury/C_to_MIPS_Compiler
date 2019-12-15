#include "../ast_structure/Node.hpp"

Node::Node(){
    std::vector<NodePtr> tmp;
    branches = tmp;
}
Node::addNode (NodePtr other){
    branches.push_back(other);
}