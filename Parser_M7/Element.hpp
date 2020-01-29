#ifndef ELEMENT
#define ELEMENT
#include "includes.hpp"
#include "Node.hpp"

class Element;
typedef const Element* ElementPtr;
typedef std::vector<ElementPtr> ElementVec;

class Element{
  public:
    Element(Production prod, ElementVec bran, std::string lit, bool leaf = false): 
            production(prod), branches(bran), literal(lit), leaf(leaf){}
    Element(Production prod, std::string lit, bool leaf = true): 
            production(prod), literal(lit), leaf(leaf){}



    Production production;
    ElementVec branches;
    std::string literal;
    bool leaf;


};


#endif