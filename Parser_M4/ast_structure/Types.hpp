#ifndef TYPES
#define TYPES

#include "includes.hpp"

class Types{
  public:
    Types();
    bool addType(const std::string& other);
    bool isType(const std::string& other) const;

  private:
    std::vector<std::string> types;

};

#endif