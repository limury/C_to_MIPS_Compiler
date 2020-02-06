#ifndef NODE
#define NODE

#include "includes.hpp"
#include <string>
#include <vector>
class Node;
typedef const Node* NodePtr;
class Operator;
typedef std::vector<NodePtr> NodeVec;

extern NodePtr parseAST();


enum ProductionType { 
    primary_expression
    , postfix_expression
    , argument_expression_list
    , unary_expression
    , unary_operator
    , cast_expression
    , multiplicative_expression
    , additive_expression
    , shift_expression
    , relational_expression
    , equality_expression
    , and_expression
    , exclusive_or_expression
    , inclusive_or_expression
    , logical_and_expression
    , logical_or_expression
    , conditional_expression
    , assignment_expression
    , assignment_operator
    , expression
    , constant_expression
    , declaration
    , declaration_specifiers
    , init_declarator_list
    , init_declarator
    , storage_class_specifier
    , type_specifier
    , struct_or_union_specifier
    , struct_or_union
    , struct_declaration_list
    , struct_declaration
    , specifier_qualifier_list
    , struct_declarator_list
    , struct_declarator
    , enum_specifier
    , enumerator_list
    , enumerator
    , type_qualifier
    , declarator
    , direct_declarator
    , pointer
    , type_qualifier_list
    , parameter_type_list
    , parameter_list
    , parameter_declaration
    , identifier_list
    , type_name
    , abstract_declarator
    , direct_abstract_declarator
    , initializer
    , initializer_list
    , statement
    , labeled_statement
    , compound_statement
    , declaration_list
    , statement_list
    , expression_statement
    , selection_statement
    , iteration_statement
    , jump_statement
    , translation_unit
    , external_declaration
    , function_definition
    , IDENTIFIER
    , CONSTANT
    , STRING_LITERAL


    , CHAR_LIT
    , NUM_LIT
    , STRING_LIT
    , FLOAT_LIT
    , Leaf
};

class Node {
  public:
    Node()
        : type(translation_unit){}

    Node(ProductionType _type, std::string* _value, std::vector<NodePtr> _branches)
        : type(_type), value(_value), branches(_branches){}

    Node(ProductionType _type, std::string* _value)
        : type(_type), value(_value){}

    Node(ProductionType _type, std::vector<NodePtr> _branches)
        : type(_type), branches(_branches){}
    
    virtual std::string getValue(){
        if (branches.size() > 0){
            std::string output = "Leaf node with value: " + *value + "\n";
        }
        else{
            std::string output = "Production with ID: " + std::to_string(type) + "\n";
        }
    }

    ProductionType type;
    std::string* value;
    std::vector<NodePtr> branches;
};

enum OperatorEnum {
    L_BRACKET,
    R_BRACKET,
    L_BRACE,
    R_BRACE,
    L_PARENTHESES,
    R_PARENTHESES,
    DOT,
    COMMA,
    PTR_OP,
    INC_OP,
    DEC_OP,
    AND_OP,
    OR_OP,
    SIZEOF,
    BIN_AND,
    BIN_NOT,
    BIN_OR,
    BIN_XOR,
    MULT,
    DIVIDE,
    MODULO,
    PLUS,
    MINUS,
    LOGICAL_NOT,
    LEFT_OP, // <<
    RIGHT_OP,// >>
    QUESTION_MARK,
    COLON,
    SEMICOLON = 21,
    EQUALS,
    MUL_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN,
    ADD_ASSIGN,
    SUB_ASSIGN,
    LEFT_ASSIGN,
    RIGHT_ASSIGN,
    AND_ASSIGN,
    XOR_ASSIGN,
    OR_ASSIGN,

    LT, GT, LE_OP, GE_OP, EQ_OP, NE_OP,

    TYPEDEF, EXTERN, STATIC, AUTO, REGISTER,

    VOID = 400, CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, SIGNED, UNSIGNED, TYPE_NAME,
    STRUCT, UNION, ENUM, 
    CONST, VOLATILE,
    ELLIPSIS, CASE, DEFAULT,
    IF, ELSE, SWITCH,
    WHILE, DO, FOR, 
    GOTO, CONTINUE, BREAK, RETURN
};

class Operator: public Node{
  public:
    Operator(OperatorEnum _op): op(_op), Node(Leaf, new std::string("")){}
    std::string getValue(){
        return std::to_string(op);
    }
    OperatorEnum op;
};


class Terminal: public Node{
  public:
    std::string value;
    Terminal(std::string _value): value(_value){}
};

typedef const Terminal* TerminalPtr;


#endif