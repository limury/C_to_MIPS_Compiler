#ifndef TYPES
#define TYPES

#include "../structures.hpp"

enum DefaultTypes { _void, _char, _short, _int, _long, _float, _double, _signed, _unsigned, _voidPtr, _charPtr, _shortPtr, _intPtr, _longPtr, _floatPtr, _doublePtr, _signedPtr, _unsignedPtr };
enum StorageSpecifier { _typedef, _extern, _static, _auto, _register, _default };
enum TypeQualifier { _const, _volatile, _default };

class Type {

    struct TypeDetails {
        DefaultTypes type;
        StorageSpecifier specifier;
        TypeQualifier qualifier;
    };
    

  public:
    Type();
  private:
    std::map<std::string, TypeDetails> details_list;
    std::map<std::string, char> char_list;
    std::map<std::string, short> short_list;
    std::map<std::string, int> int_list;
    std::map<std::string, long> long_list;
    std::map<std::string, float> float_list;
    std::map<std::string, double> double_list;
    std::map<std::string, signed> signed_list;
    std::map<std::string, unsigned> unsigned_list;
    
    std::map<std::string, void*> voidPtr_list;
    std::map<std::string, char*> charPtr_list;
    std::map<std::string, short*> shortPtr_list;
    std::map<std::string, int*> intPtr_list;
    std::map<std::string, long*> longPtr_list;
    std::map<std::string, float*> floatPtr_list;
    std::map<std::string, double*> doublePtr_list;
    std::map<std::string, signed*> signedPtr_list;
    std::map<std::string, unsigned*> unsignedPtr_list;


};

#endif