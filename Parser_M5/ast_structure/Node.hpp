#ifndef NODE
#define NODE

#include "includes.hpp"
#include "../structures.hpp"


class Node {
  public:
    Node();
    void addNode(const Declaration& other);
    void addNode(const Function& other)

  protected:
    std::vector<Function> function_branches;
    std::vector<Declaration> declaration_branches;
};


#endif