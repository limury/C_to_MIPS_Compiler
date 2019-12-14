#ifndef NODE
#define NODE

#include "includes.hpp"
#include "../structures.hpp"


class Node {
  public:
    Node();
    void addNode(RootNode other);

  protected:
    std::vector<NodePtr> branches;
};


#endif