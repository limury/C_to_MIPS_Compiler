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
extern std::map<std::string, std::string> variableMap;

inline std::string getProduction (int val){
    switch(val){
    case 0:
        return "primary_expression";
    case 1:
        return "postfix_expression";
    case 2: return 
    "argument_expression_list";
    case 3: return 
    "unary_expression";
    case 4: return 
        "unary_operator";
    case 5: return 
        "cast_expression";
    case 6: return 
        "multiplicative_expression";
    case 7: return 
        "additive_expression";
    case 8: return 
        "shift_expression";
    case 9: return 
        "relational_expression";
    case 10: return 
        "equality_expression";
    case 11: return 
        "and_expression";
    case 12: return 
        "exclusive_or_expression";
    case 13: return 
        "inclusive_or_expression";
    case 14: return 
        "logical_and_expression";
    case 15: return 
        "logical_or_expression";
    case 16: return 
        "conditional_expression";
    case 17: return 
        "assignment_expression";
    case 18: return 
        "assignment_operator";
    case 19: return 
        "expression";
    case 20: return 
        "constant_expression";
    case 21: return 
        "declaration";
    case 22: return 
        "declaration_specifiers";
    case 23: return 
        "init_declarator_list";
    case 24: return 
        "init_declarator";
    case 25: return 
        "storage_class_specifier";
    case 26: return 
        "type_specifier";
    case 27: return 
        "struct_or_union_specifier";
    case 28: return 
        "struct_or_union";
    case 29: return 
        "struct_declaration_list";
    case 30: return 
        "struct_declaration";
    case 31: return 
        "specifier_qualifier_list";
    case 32: return 
        "struct_declarator_list";
    case 33: return 
        "struct_declarator";
    case 34: return 
        "enum_specifier";
    case 35: return 
        "enumerator_list";
    case 36: return 
        "enumerator";
    case 37: return 
        "type_qualifier";
    case 38: return 
        "declarator";
    case 39: return 
        "direct_declarator";
    case 40: return 
        "pointer";
    case 41: return 
        "type_qualifier_list";
    case 42: return 
        "parameter_type_list";
    case 43: return 
        "parameter_list";
    case 44: return 
        "parameter_declaration";
    case 45: return 
        "identifier_list";
    case 46: return 
        "type_name";
    case 47: return 
        "abstract_declarator";
    case 48: return 
        "direct_abstract_declarator";
    case 49: return 
        "initializer";
    case 50: return 
        "initializer_list";
    case 51: return 
        "statement";
    case 52: return 
        "labeled_statement";
    case 53: return 
        "compound_statement";
    case 54: return 
        "declaration_list";
    case 55: return 
        "statement_list";
    case 56: return 
        "expression_statement";
    case 57: return 
        "selection_statement";
    case 58: return 
        "iteration_statement";
    case 59: return 
        "jump_statement";
    case 60: return 
        "translation_unit";
    case 61: return 
        "external_declaration";
    case 62: return 
        "function_definition";
    case 63: return 
        "IDENTIFIER";
    case 64: return 
        "CONSTANT";
    case 65: return 
        "STRING_LITERAL";
    case 66: return 
        "CHAR_LIT";
    case 67: return 
        "NUM_LIT";
    case 68: return 
        "STRING_LIT";
    case 69: return 
        "FLOAT_LIT";
    case 70: return
        "Leaf";
    }
}

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
    
    virtual std::string getValue() const{
        
        if (branches.size() <= 0){
            return "Leaf node with value: " + *value + "\n";
        }
        else{
            return getProduction(type) + "\n";
        }
    }

    ProductionType type;
    std::string* value;
    std::vector<NodePtr> branches;
    NodePtr parent;
};

inline std::string getOperator(int val){
    switch (val){
    case 0:
        return "[";
    case 1:
        return "]";
    case 2:
        return "{";
    case 3:
        return "}";
    case 4:
        return "(";
    case 5:
        return ")";
    case 6:
        return ".";
    case 7:
        return ",";
    case 8:
        return "PTR_OP";
    case 9:
        return "INC_OP";
    case 10:
        return "DEC_OP";
    case 11:
        return "AND_OP";
    case 12:
        return "OR_OP";
    case 13:
        return "SIZEOF";
    case 14:
        return "BIN_AND";
    case 15:
        return "BIN_NOT";
    case 16:
        return "BIN_OR";
    case 17:
        return "BIN_XOR";
    case 18:
        return "MULT";
    case 19:
        return "DIVIDE";
    case 20:
        return "MODULO";
    case 21:
        return "PLUS";
    case 22:
        return "MINUS";
    case 23:
        return "LOGICAL_NOT";
    case 24:
        return "LEFT_OP";
    case 25:
        return "RIGHT_OP";
    case 26:
        return "QUESTION_MARK";
    case 27:
        return ":";
    case 28:
        return ";";
    case 29:
        return "EQUALS";
    case 30:
        return "MUL_ASSIGN";
    case 31:
        return "DIV_ASSIGN";
    case 32:
        return "MOD_ASSIGN";
    case 33:
        return "ADD_ASSIGN";
    case 34:
        return "SUB_ASSIGN";
    case 35:
        return "LEFT_ASSIGN";
    case 36:
        return "RIGHT_ASSIGN";
    case 37:
        return "AND_ASSIGN";
    case 38:
        return "XOR_ASSIGN";
    case 39:
        return "OR_ASSIGN";
    case 40:
        return "LT";
    case 41:
        return "GT";
    case 42:
        return "LE_OP";
    case 43:
        return "GE_OP";
    case 44:
        return "EQ_OP";
    case 45:
        return "NE_OP";
    case 46:
        return "TYPEDEF";
    case 47:
        return "EXTERN";
    case 48:
        return "STATIC";
    case 49:
        return "AUTO";
    case 50:
        return "REGISTER";
    case 51:
        return "VOID";
    case 52:
        return "CHAR";
    case 53:
        return "SHORT";
    case 54:
        return "INT";
    case 55:
        return "LONG";
    case 56:
        return "FLOAT";
    case 57:
        return "DOUBLE";
    case 58:
        return "SIGNED";
    case 59:
        return "UNSIGNED";
    case 60:
        return "TYPE_NAME";
    case 61:
        return "STRUCT";
    case 62:
        return "UNION";
    case 63:
        return "ENUM";
    case 64:
        return "CONST";
    case 65:
        return "VOLATILE";
    case 66:
        return "ELLIPSIS";
    case 67:
        return "CASE";
    case 68:
        return "DEFAULT";
    case 69:
        return "IF";
    case 70:
        return "ELSE";
    case 71:
        return "SWITCH";
    case 72:
        return "WHILE";
    case 73:
        return "DO";
    case 74:
        return "FOR";
    case 75:
        return "GOTO";
    case 76:
        return "CONTINUE";
    case 77:
        return "BREAK";
    case 78:
        return "RETURN";
    }
}

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
    SEMICOLON,
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

    VOID, CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, SIGNED, UNSIGNED, TYPE_NAME,
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
    std::string getValue() const{
        return getOperator(op) + "\n";
    }
    OperatorEnum op;
};


class Terminal: public Node{
  public:
    std::string value;
    Terminal(std::string _value): value(_value){}
    std::string getValue() const{
        return "Terminal with value: " + value + "\n";
    }
};

typedef const Terminal* TerminalPtr;


#endif