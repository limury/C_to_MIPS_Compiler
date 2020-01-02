#ifndef NODE
#define NODE

#include "includes.hpp"
#include "structures.hpp"

class Node;

typedef const Node* NodePtr;

class Node {
  public:
    Node();
    void addNode(TranslationUnitPtr other);

  protected:
  
    std::vector<TranslationUnitPtr> branches;
};


#endif