#ifndef NODE
#define NODE

#include "includes.hpp"
#include "structures.hpp"

class Node;

typedef const Node* NodePtr;

class Node {
  public:
    Node();
    void addNode(NodePtr other);

  protected:
    std::vector<NodePtr> branches;
};


#endif