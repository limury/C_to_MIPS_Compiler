#include "../ast_structure/Types.hpp"
    
Types::Types(){
    types = std::vector<std::string> {"void", "char", "short", "int", "long", "float", "double", "signed", "unsigned"};
}

bool Types::addType(const std::string& other){
    if (!this->isType(other)){
        types.push_back(other);
        return true;
    }
    return false;
}


bool Types::isType(const std::string& other) const{
    for (std::vector<std::string>::const_iterator it = types.begin(); it != types.end(); it++){
        if (*it == other){
            return true;
        }
    }
    return false;
}