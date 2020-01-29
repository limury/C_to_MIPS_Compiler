#ifndef NODE
#define NODE

#include "includes.hpp"

enum Production { 
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
    , leaf
};

struct Element;




typedef const Node* NodePtr;
class Node {
  public:
    Production production;
    std::vector<NodePtr> branches;

    Node (Production prod, std::vector<NodePtr> bran);
};


#endif