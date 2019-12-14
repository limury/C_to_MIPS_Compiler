
#include "../ast_structure/RootNode.hpp"

RootNode::RootNode (NodePtr other){
    branches.push_back(other);
}