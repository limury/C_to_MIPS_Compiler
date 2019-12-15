#ifndef ROOTNODE
#define ROOTNODE

#include "includes.hpp"
#include "../structures.hpp"

class RootNode {
  public:
    RootNode();
    void addNode(NodePtr other);

  protected:
    std::vector<NodePtr> branches;
};

#endif