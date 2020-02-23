#include "Node.hpp"

std::string getProduction2 (int val){
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