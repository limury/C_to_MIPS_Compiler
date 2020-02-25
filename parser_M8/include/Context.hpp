#ifndef CONTEXT
#define CONTEXT

#include "Node.hpp"

using namespace std;

class Instruction {
  public:
    std::string function;
    std::string arg1, arg2, arg3;
    
    enum { LABEL, INSTRUCTION } type;
};

class Context {
  public:
    Context():  id(0)  {}

    std::string makeLabel( const string& label ){
        return "_" + label + "_" + to_string(++id);
    }




  private:
    int id;
    map<string, std::vector<string> > variable_table; // storing variable and value. It is a vector because arrays.
    
    map<string, string> type_table;
    map<string, int> pointer_table;
    map<string, int> size_table;
};

#endif