#ifndef DECLARATIONS
#define DECLARATIONS
#include "../includes.hpp"
#include "BaseClasses.hpp"

typedef const Declaration* DeclarationPtr;
typedef const Initializer* InitializerPtr;


// Recursively flattens the array of declarations;
// When the rule is a single Declaration it creates a new list
// If instead it is a declaration plus a list, the rule returns a 
// Pointer to list passed as parameter with the new declaration appended

// We use the general RootPtr's instead of Declaration* or Initializer* 
// as we don't know if it will simply be cast to an expression or something else 
// due to the rule 
//initializer
//	  : assignment_expression


class ExternalDeclarationList : public Root {
  public:
    ExternalDeclarationList( RootPtr declList, RootPtr decl ){
      declList->append(decl);
      *this = *declList;
    }

    ExternalDeclarationList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }

    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;

};

class FunctionDefinition : public Root {
  public:
    FunctionDefinition(RootPtr p1, RootPtr p2, RootPtr p3): _declarationSpecifier(p1), _declarator(p2), _compoundStatement(p3) {}

  protected:
    RootPtr _declarationSpecifier, _declarator, _compoundStatement;
};


class DeclarationList : public Root {
  public:
    DeclarationList( RootPtr declList, RootPtr decl ){
      declList->append(decl);
      *this = *declList;
    }

    DeclarationList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }

    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;

};


class InitializerList: public Root {
  public:
    InitializerList( RootPtr initList, RootPtr init ){
      initList->append(init);
      *this = *initList;
    }

    InitializerList(RootPtr init){
      _list = new vector<RootPtr>;
      _list->push_back(init);
    }

    void append(RootPtr init){
      this->_list->push_back(init);
    }

  protected:
    vector<RootPtr>* _list;

};

// Used for initializer, the format is '{' initializer list '}'
// Have to keep it as a wrapper as otherwise, simply casting it to an initializer list
// would cause it to flatten due to the recursive nature of the InitializerList class
class Initializer : public Root{
  public:
    Initializer(InitializerList* init_list): _list(init_list) {}

  protected:
    InitializerList* _list;
};


// Direct Abstract Declarator can be used for arrays or functions hence we make 2 classes for them
// The function version isn't really needed as we don't implement function pointers.

class ArrayDirectAbstractDeclarator : public Root {
  public:
    ArrayDirectAbstractDeclarator(RootPtr abst, RootPtr expr): _abstractDeclarator(abst), _expr(expr) {}

  protected:
    RootPtr _abstractDeclarator;
    RootPtr _expr;
};

class FunctionDirectAbstractDeclarator : public Root {
  public:
    FunctionDirectAbstractDeclarator(RootPtr abst, RootPtr expr): _abstractDeclarator(abst), _paramList(expr) {}

  protected:
    RootPtr _abstractDeclarator;
    RootPtr _paramList;
};


// abstract_declarator production
// Either fields are optional

class AbstractDeclarator : public Root {
  public:
    AbstractDeclarator(RootPtr pointer, RootPtr directAbstractDeclarator): _pointer(pointer), _directAbstractDeclarator(directAbstractDeclarator) {}

  protected:
    RootPtr _pointer;
    RootPtr _directAbstractDeclarator;
};




// type_name production. 

class TypeName : public Root {
  public:
    TypeName (RootPtr specifierList, RootPtr abstractDeclarator): _specifierList(specifierList), _abstractDeclarator(abstractDeclarator) {}
  
  protected:
    RootPtr _specifierList;
    RootPtr _abstractDeclarator;
};


// Parameters

class ParameterDeclaration : public Root {
  public:
    ParameterDeclaration(RootPtr declSpec, RootPtr decl, RootPtr absDecl): _declarationSpecifier(declSpec), _declarator(decl), _abstractDeclarator(absDecl) {}
  
  protected:  
    RootPtr _declarationSpecifier;
    RootPtr _declarator;
    RootPtr _abstractDeclarator;
};

class ParameterList : public Root {
  public:
    ParameterList( RootPtr declList, RootPtr decl ){
      declList->append(decl);
      *this = *declList;
    }

    ParameterList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }

    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};


// Pointer
// pointer_num is simply the number of '*' s

class Pointer : public Root {
  public:
    Pointer(Pointer* ptr, bool single = true){
        if (single){
            pointer_num = new int(1);}
        else{
            ptr->pointer_num += 1;
            *this = *ptr;
        }
            
    }

    int* pointer_num;
};


// Declarators

class IdentifierDirectDeclarator : public Root {
  public:
    IdentifierDirectDeclarator(const string& name): _identifier(name) {}

  protected:
    string _identifier;
};

class ArrayDirectDeclarator : public Root {
  public:
    ArrayDirectDeclarator(RootPtr dirDecl, RootPtr expr): _directDeclarator(dirDecl), _expression(expr) {}

  protected:
    RootPtr _directDeclarator;
    RootPtr _expression;
};

class FunctionDirectDeclarator : public Root {
  public:
    FunctionDirectDeclarator(RootPtr dirDecl, RootPtr expr): _directDeclarator(dirDecl), _parameterList(expr) {}

  protected:
    RootPtr _directDeclarator;
    RootPtr _parameterList;
};

class Declarator : public Root {
  private:
    Declarator(RootPtr ptr, RootPtr dirDecl): _pointer(ptr), _directDeclarator(dirDecl) {}

  protected:
    RootPtr _pointer, _directDeclarator;

};


// enumerators

class Enumerator : public Root {
  public:
    Enumerator (string name, RootPtr expr): _identifier(name), _expr(expr) {}
  
  protected:
    string _identifier;
    RootPtr _expr;
};

class EnumeratorList : public Root {
  public:
    EnumeratorList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }

    EnumeratorList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }

    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};

class EnumeratorSpecifier : public Root {
  public:
    EnumeratorSpecifier(string name, RootPtr enumList): _identifier(name), _enumList(enumList) {}

  protected:
    string _identifier;
    RootPtr _enumList;
};


// Structs

class StructDeclarator : public Root {
  public:
    StructDeclarator(RootPtr decl, RootPtr expr): _declarator(decl), _expression(expr) {}

  protected:
    RootPtr _declarator, _expression;
};

class StructDeclaratorList : public Root {
  public:
    StructDeclaratorList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }
    StructDeclaratorList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }
    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};


class StructDeclaration : public Root {
  public:
    StructDeclaration(RootPtr speclist, RootPtr structlist): _specifierList(speclist), _structDeclaratorList(structlist) {}

  protected:
    RootPtr _specifierList, _structDeclaratorList;
};

class StructDeclarationList : public Root {
  public:
    StructDeclarationList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }
    StructDeclarationList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }
    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};

class StructSpecifier : public Root {
  public: 
    StructSpecifier(string name, RootPtr decl): _identifier(name), _declarationList(decl) {}

  protected:
    string _identifier;
    RootPtr _declarationList;
};



// Types

class SpecifierList : public Root {
  public:
    SpecifierList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }
    SpecifierList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }
    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};


enum primitiveTypes { VOID, CHAR, SHORT, LONG, INT, FLOAT, DOUBLE, SIGNED, UNSIGNED }

class PrimitiveType : public Root {
    public:
    PrimitiveType(primitiveTypes type): _type(type) {}

    protected:
    primitiveTypes _type;
};

class TypedefType : public Root {
    public:
    TypedefType(const string& name): _type(name) {}

    protected:
    string _type;
};


// Declarators

class InitDeclarator : public Root {
  public:
    InitDeclarator(RootPtr decl, RootPtr init): _declarator(decl), _initializer(init) {}

  protected:
    RootPtr _declarator, _initializer;
};

class InitDeclaratorList : public Root {
    public:
    InitDeclaratorList( RootPtr list, RootPtr decl ){
      list->append(decl);
      *this = *list;
    }
    InitDeclaratorList(RootPtr decl){
      _list = new vector<RootPtr>;
      _list->push_back(decl);
    }
    void append(RootPtr decl){
      this->_list->push_back(decl);
    }

  protected:
    vector<RootPtr>* _list;
};


// Declarations

class TypedefDeclarationSpecifier : public Root {
  public:
    TypedefDeclarationSpecifier(RootPtr decl): _declarationSpecifier(decl) {}

  protected:
    RootPtr _declarationSpecifier;
};

class SpecDeclarationSpecifier : public Root {
  public:
    SpecDeclarationSpecifier( RootPtr list, RootPtr decl ): _typeSpecifier(list), _declarationSpecifier(decl) {}

  protected:
    RootPtr _typeSpecifier, _declarationSpecifier;
};

class Declaration : public Root {
  public:
    Declaration(RootPtr declSpec, RootPtr initDecl): _declarationSpecifier(declSpec), _initDeclaratorList(initDecl) {}
  
  protected:
    RootPtr _declarationSpecifier, _initDeclaratorList;
};



#endif