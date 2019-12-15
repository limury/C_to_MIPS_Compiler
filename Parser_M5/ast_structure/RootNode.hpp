#ifndef ROOTNODE
#define ROOTNODE

#include "includes.hpp"
#include "../structures.hpp"

class RootNode {
  public:
    RootNode();
    void addNode(const Function* other);
    void addNode(const Declaration* other);

  protected:
    std::vector<const Function*> functions;
    std::vector<const Declaration*> declarations;
};

#endif