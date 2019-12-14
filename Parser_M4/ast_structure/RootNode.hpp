#ifndef ROOTNODE
#define ROOTNODE

#include "includes.hpp"
#include "../structures.hpp"

class RootNode : public Node{
  public:
    RootNode(NodePtr other);
};

#endif