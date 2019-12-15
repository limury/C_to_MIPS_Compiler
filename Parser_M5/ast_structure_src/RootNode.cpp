#include "../ast_structure/Node.hpp"

RootNode::RootNode(){
    std::vector<NodePtr> tmp;
    branches = tmp;
}
void RootNode::addNode (NodePtr other){
    branches.push_back(other);
}