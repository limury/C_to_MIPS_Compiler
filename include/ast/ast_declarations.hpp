#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP

//************************************************************
//--------------------DECLARATION LIST------------------------
//************************************************************

class DeclarationList : public BaseList {           //MIPS DONE
public:
    DeclarationList(BaseList *_list, BaseNode *_declaration) : BaseList(_list), declaration(_declaration) {}
    ~DeclarationList() {
        if (list != NULL) delete list;
        delete declaration;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        declaration->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) list->printPy(os, context);
        declaration->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (list != NULL) list->generateMIPS(context, instructions);
        declaration->generateMIPS(context, instructions);
    }

protected:
    BaseNode *declaration;
};

//************************************************************
//-----------------------INITIALIZER--------------------------  //TODO: init lists?
//************************************************************

class InitializerListHolder : public BaseExpression {
public:
    InitializerListHolder(BaseExpressionList *_initList) : initList(_initList) {}
    ~InitializerListHolder() { delete initList; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Initializer (List):" << std::endl;
        initList->print(os, level+1);
    }

protected:
    BaseExpressionList *initList;
};

class InitializerList : public BaseExpressionList {
public:
    InitializerList(BaseExpressionList *_list, BaseExpression *_init) : BaseExpressionList(_list), init(_init) {}
    ~InitializerList() {
        if (list != NULL) delete list;
        delete init;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        init->print(os, level);
    }

protected:
    BaseExpression *init;
};

//************************************************************
//-------------------ABSTRACT DECLARATION---------------------  //TODO: abstracts?
//************************************************************

class AbstractArray : public BaseNode {             //MIPS DONE
public:
    AbstractArray(BaseNode *_absDec, BaseExpression *_expr) : absDec(_absDec), expr(_expr) {}
    ~AbstractArray() {
        if (absDec != NULL) delete absDec;
        if (expr != NULL) delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Abstract Array:" << std::endl;
        if (absDec != NULL) absDec->print(os, level+1);
        if (expr != NULL) {
            os << indent(level+1) << "Size:" << std::endl;
            expr->print(os, level+2);
        }
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (absDec != NULL) absDec->generateMIPS(context, instructions);
        if (!context.decFlags().init) context.tempDec.type.arraySizes.push_back(expr->eval());
    }

protected:
    BaseNode *absDec;
    BaseExpression *expr;
};

class AbstractFunc : public BaseNode {              // not doing func pointers so no need
public:
    AbstractFunc(BaseNode *_absDec, BaseList *_params) : absDec(_absDec), params(_params) {}
    ~AbstractFunc() {
        if (absDec != NULL) delete absDec;
        if (params != NULL) delete params;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Abstract Function:" << std::endl;
        if (absDec != NULL) absDec->print(os, level+1);
        if (params != NULL) {
            os << indent(level+1) << "Parameters:" << std::endl;
            params->print(os, level+2);
        }
    }

protected:
    BaseNode *absDec;
    BaseList *params;
};

class AbstractDeclarator : public BaseNode {        //MIPS DONE
public:
    AbstractDeclarator(BaseList *_pointer, BaseNode *_absDec) : pointer(_pointer), absDec(_absDec) {}
    ~AbstractDeclarator() {
        if (pointer != NULL) delete pointer;
        if (absDec != NULL) delete absDec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Abstract Declarator:" << std::endl;
        if (pointer != NULL) {
            os << indent(level+1) << "Pointer:" << std::endl;
            pointer->print(os, level+2);
        }
        if (absDec != NULL) absDec->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (!context.decFlags().init && pointer != NULL) context.tempDec.type.pointerNum = pointer->size();
        if (absDec != NULL) absDec->generateMIPS(context, instructions);
    }

protected:
    BaseList *pointer;
    BaseNode *absDec;
};

//************************************************************
//------------------------TYPE NAME---------------------------
//************************************************************

class TypeName : public BaseNode {              //MIPS DONE
public:
    TypeName(BaseList *_specList, BaseNode *_absDec) : specList(_specList), absDec(_absDec) {}
    ~TypeName() {
        delete specList;
        if (absDec != NULL) delete absDec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Type Name:" << std::endl;
        specList->print(os, level+1);
        if (absDec != NULL) absDec->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        context.tempDec = {};
        specList->generateMIPS(context, instructions);
        if (absDec != NULL) absDec->generateMIPS(context, instructions);
    }

protected:
    BaseList *specList;
    BaseNode *absDec;
};

//************************************************************
//-----------------------PARAMETERS---------------------------
//************************************************************

class ParamDeclaration : public BaseNode {      //MIPS DONE
public:
    ParamDeclaration(BaseNode *_decSpec, BaseNode *_dec, BaseNode *_absDec) : decSpec(_decSpec), dec(_dec), absDec(_absDec) {}
    ~ParamDeclaration() {
        delete decSpec;
        if (dec != NULL) delete dec;
        if (absDec != NULL) delete absDec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Parameter Declaration:" << std::endl;
        decSpec->print(os, level+1);
        if (dec != NULL) dec->print(os, level+1);
        if (absDec != NULL) absDec->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (dec != NULL) dec->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        context.decFlags().functionDef = false;

        context.tempDec = {};
        
        if (dec != NULL) dec->generateMIPS(context, instructions);
        if (absDec != NULL) absDec->generateMIPS(context, instructions);
        decSpec->generateMIPS(context, instructions);

        context.funcMap[context.decFlags().funcName].params.push_back({context.tempDec.identifier, context.tempDec.type});

        context.decFlags().functionDef = true;
    }

protected:
    BaseNode *decSpec, *dec, *absDec;
};

class ParamList : public BaseList {             //MIPS DONE
public:
    ParamList(BaseList *_list, BaseNode *_param) : BaseList(_list), param(_param) {}
    ~ParamList() {
        if (list != NULL) delete list;
        delete param;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        param->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) {
            list->printPy(os, context);
            os << ", ";
        }
        param->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (list != NULL) list->generateMIPS(context, instructions);
        param->generateMIPS(context, instructions);
    }

protected:
    BaseNode *param;
};

//************************************************************
//-------------------------POINTER----------------------------
//************************************************************

class Pointer : public BaseList {               //MIPS NOT NEEDED?    
public:
    Pointer(BaseList *_list) : BaseList(_list) {}
    ~Pointer() { if (list != NULL) delete list; }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        os << indent(level) << "*" << std::endl;
    }

protected:
};

//************************************************************
//-----------------------DECLARATORS--------------------------
//************************************************************

class DeclaratorIdentifier : public BaseNode {  //MIPS DONE
public:
    DeclaratorIdentifier(const std::string &_iden) : identifier(_iden) {}
    ~DeclaratorIdentifier() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator (Identifier): " << identifier << std::endl;
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << identifier;
        if (context.declaration)
            os << " = 0";
        if (context.globalDec)
            context.globals.push_back(identifier);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (context.decFlags().functionDef) {
            context.decFlags().funcName = identifier;
        } else if (context.decFlags().init && context.stack.size() == 1) {      // is it initializing and global
            // means it missed the initializer
            instructions.push_back({".data", "", "", "", 0, Instruction::E});
            instructions.push_back({".global", context.tempDec.identifier, "", "", 0, Instruction::S});
            // .type   x, @object
            instructions.push_back({".type", context.tempDec.identifier, "@object", "", 0, Instruction::SS});
            instructions.push_back({"list_start","","","",0, Instruction::LIST});
            instructions.push_back({"label", context.tempDec.identifier, "", "", 0, Instruction::L});
            int zeroNum = 1;
            for (int i = 0; i < context.tempDec.type.arraySizes.size(); ++i) {
                zeroNum *= context.tempDec.type.arraySizes[i];
            }
            if (zeroNum == 1) instructions.push_back({"list_end","","","",0, Instruction::LIST});    // new line if not an array
            instructions.push_back({" .word", "", "", "", 0, Instruction::N});
            for (int i = 1; i < zeroNum - 1; ++i) {
                instructions.push_back({",", "", "", "", 0, Instruction::N});
            }
            if (zeroNum != 1) {
                instructions.push_back({"list_end","","","",0, Instruction::LIST}); // last element
                instructions.push_back({",", "", "", "", 0, Instruction::N});
            }
        } else {
            context.tempDec.identifier = identifier;
        }
    }

protected:
    std::string identifier;
};

class DeclaratorArray : public BaseNode {       //MIPS DONE
public:
    DeclaratorArray(BaseNode *_dec, BaseExpression *_expr) : dec(_dec), expr(_expr) {}
    ~DeclaratorArray() {
        delete dec;
        if (expr != NULL) delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator (Array):" << std::endl;
        dec->print(os, level+1);
        if (expr != NULL) {
            os << indent(level+1) << "Size: " << std::endl;
            expr->print(os, level+2);
        }
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        dec->generateMIPS(context, instructions);
        if (!context.decFlags().init) context.tempDec.type.arraySizes.push_back(expr->eval());
    }

protected:
    BaseNode *dec;
    BaseExpression *expr;
};

class DeclaratorFunc : public BaseNode {        //MIPS DONE
public:
    DeclaratorFunc(BaseNode *_dec, BaseList *_params) : dec(_dec), params(_params) {}
    ~DeclaratorFunc() {
        delete dec;
        if (params != NULL) delete params;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator (Function):" << std::endl;
        dec->print(os, level+1);
        if (params != NULL) {
            os << indent(level+1) << "Parameters: " << std::endl;
            params->print(os, level+2);
        }
    }

    void printPy(std::ostream &os, PyContext &context) {
        context.globalDec = false;
        dec->printPy(os, context);
        os << "(";
        if (params != NULL) params->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        context.decFlags().functionDef = true;
        dec->generateMIPS(context, instructions);
        if (params != NULL) {
            context.addScopeContext();
            context.funcMap[context.decFlags().funcName].params = {};
            params->generateMIPS(context, instructions);
            context.subScopeContext();
        }
    }

protected:
    BaseNode *dec;
    BaseList *params;
};

class Declarator : public BaseNode {            //MIPS DONE   
public:
    Declarator(BaseList *_pointer, BaseNode *_dec) : pointer(_pointer), dec(_dec) {}
    ~Declarator() {
        delete pointer;
        delete dec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator:" << std::endl;
        os << indent(level+1) << "Pointer:" << std::endl;
        pointer->print(os, level+2);
        dec->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (!context.decFlags().init) context.tempDec.type.pointerNum = pointer->size();
        dec->generateMIPS(context, instructions);
    }

protected:
    BaseList *pointer;
    BaseNode *dec;
};

//************************************************************
//-----------------------ENUMERATORS--------------------------
//************************************************************

class EnumElement : public BaseNode {               //MIPS DONE
public:
    EnumElement(const std::string &_iden, BaseExpression *_expr) : identifier(_iden), expr(_expr) {}
    ~EnumElement() { if (expr != NULL) delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Enum Element: " << identifier << std::endl;
        if (expr != NULL)
            expr->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int val = expr == NULL ? context.enumFlags().lastVal + 1 : expr->eval();
        context.enumFlags().lastVal = val;
        context.addCustomDec(identifier, {0,{{INT_T, "int"}},{}}, instructions);
        if (context.stack.size() == 1) {
            instructions.push_back({".global", identifier, "", "", 0, Instruction::S});
            // .type   x, @object
            instructions.push_back({".type", identifier, "@object", "", 0, Instruction::SS});
            instructions.push_back({"list_start", "", "", "", 0, Instruction::LIST});
            instructions.push_back({"label", identifier, "", "", 0, Instruction::L});
            instructions.push_back({"list_end", "", "", "", 0, Instruction::LIST});
            instructions.push_back({" .word", "", "", "", val, Instruction::N});
        } else {
            int reg = context.chooseReg();
            context.pushToStack({reg}, instructions);
            instructions.push_back({"li", regMap[reg], "", "", val, Instruction::SN});
            context.writeStack(reg, context.varMap()[identifier].offset, instructions);
            context.pullFromStack({reg}, instructions);
        }
    }

protected:
    std::string identifier;
    BaseExpression *expr;
};

class EnumElemList : public BaseList {              //MIPS DONE
public:
    EnumElemList(BaseList *_list, BaseNode *_enumElem) : BaseList(_list), enumElem(_enumElem) {}
    ~EnumElemList() {
        if (list != NULL) delete list;
        delete enumElem;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        enumElem->print(os, level);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (list != NULL) list->generateMIPS(context, instructions);
        enumElem->generateMIPS(context, instructions);
    }

protected:
    BaseNode *enumElem;
};

class EnumSpecifier : public BaseNode {             //MIPS DONE
public:
    EnumSpecifier(const std::string &_iden, BaseList *_elemList) : identifier(_iden), elemList(_elemList) {}
    EnumSpecifier(BaseList *_elemList) : elemList(_elemList) {}
    ~EnumSpecifier() { if (elemList != NULL) delete elemList; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Enumerator:" << std::endl;
        if (identifier != "") os << indent(level+1) << "Identifier: " << identifier << std::endl;
        if (elemList != NULL) {
            os << indent(level+1) << "Contents: " << std::endl;
            elemList->print(os, level+2);
        }
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        context.tempDec.type.typeSpecifiers.push_back({INT_T, "int"});
        if (elemList != NULL) {
            if (context.stack.size() == 1) instructions.push_back({".data", "", "", "", 0, Instruction::E});
            elemList->generateMIPS(context, instructions);
            if (context.stack.size() == 1) instructions.push_back({".text", "", "", "", 0, Instruction::E});       // need to specify the rest is text (funcs will do it themselves)
        }
    }

protected:
    std::string identifier = ""; 
    BaseList *elemList;
};

//************************************************************
//-------------------------STRUCTS----------------------------      //TODO: structs (probs wont do)
//************************************************************

class StructDeclarator : public BaseNode {
public:
    StructDeclarator(BaseNode *_dec, BaseExpression *_expr) : dec(_dec), expr(_expr) {}
    ~StructDeclarator() {
        if (dec != NULL) delete dec;
        delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Struct Declarator:" << std::endl;
        if (dec != NULL) dec->print(os, level+1);
        os << indent(level+1) << "Bit Width:" << std::endl;
        expr->print(os, level+2);
    }

protected:
    BaseNode *dec;
    BaseExpression *expr;
};

class StructDeclaratorList : public BaseList {
public:
    StructDeclaratorList(BaseList *_list, BaseNode *_dec) : BaseList(_list), dec(_dec) {}
    ~StructDeclaratorList() {
        if (list != NULL) delete list;
        delete dec;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        dec->print(os, level);
    }

protected:
    BaseNode *dec;
};

class StructDeclaration : public BaseNode {
public:
    StructDeclaration(BaseList *_specList, BaseList *_structDecList) : specList(_specList), structDecList(_structDecList) {}
    ~StructDeclaration() {
        delete specList;
        delete structDecList;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Struct Declaration:" << std::endl;
        os << indent(level+1) << "Specifiers:" << std::endl;
        specList->print(os, level+2);
        os << indent(level+1) << "Declarators:" << std::endl;
        structDecList->print(os, level+2);
    }

protected:
    BaseList *specList, *structDecList;
};

class StructDeclarationList : public BaseList {
public:
    StructDeclarationList(BaseList *_list, BaseNode *_structDec) : BaseList(_list), structDec(_structDec) {}
    ~StructDeclarationList() {
        if (list != NULL) delete list;
        delete structDec;
    }

    void print(std::ostream &os, int level) { 
        if (list != NULL) list->print(os, level);
        structDec->print(os, level);
    }

protected:
    BaseNode *structDec;
};

class StructSpecifier : public BaseNode {
public:
    StructSpecifier(const std::string &_iden, BaseList *_structList) : identifier(_iden), structList(_structList) {}
    StructSpecifier(BaseList *_structList) : structList(_structList) {}
    ~StructSpecifier() { if (structList != NULL) delete structList; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Struct Specifier:" << std::endl;
        if (identifier != "") 
            os << indent(level+1) << "Identifier: " << identifier << std::endl;
        if (structList != NULL) {
            os << indent(level+1) << "Declarations:" << std::endl;
            structList->print(os, level+2);
        }
    }

protected:
    std::string identifier = "";
    BaseList *structList;
};

//************************************************************
//---------------------TYPE SPECIFIERS------------------------
//************************************************************

class BasicTypeSpec : public BaseNode {         //MIPS DONE
public:
    BasicTypeSpec(typeEnum _type) : type(_type) {}
    ~BasicTypeSpec() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Type: " << typeStrings.at(type) << std::endl;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (context.decFlags().functionDef) {
            context.funcMap[context.decFlags().funcName].retType.typeSpecifiers.push_back({type, typeStrings.at(type)});
            context.decFlags().functionDef = false;     // last thing to be defined in function
        } else {
            context.tempDec.type.typeSpecifiers.push_back({type, typeStrings.at(type)});
        }
    }

protected:
    typeEnum type;
};

class TypeDefTypeSpec : public BaseNode {       //MIPS DONE
public:
    TypeDefTypeSpec(const std::string &_type) : type(_type) {}
    ~TypeDefTypeSpec() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "TypeDef Type: " << type << std::endl;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (context.decFlags().functionDef) {
            //context.funcMap[context.decFlags().funcName].retType.typeSpecifiers.push_back({TYPEDEF_TYPE_T, type});
            context.funcMap[context.decFlags().funcName].retType = context.typeMap()[type];
            context.decFlags().functionDef = false;     // last thing to be defined in function
        } else {
            //context.tempDec.type.typeSpecifiers.push_back({TYPEDEF_TYPE_T, type});
            context.tempDec.type = context.typeMap()[type];
        }
    }

protected:
    std::string type;
};

class TypeSpecList : public BaseList {          //MIPS DONE   
public:
    TypeSpecList(BaseList *_list, BaseNode *_spec) : BaseList(_list), spec(_spec) {}
    ~TypeSpecList() {
        if (list != NULL) delete list;
        delete spec;
    }

    void print(std::ostream &os, int level) {
        spec->print(os, level);
        if (list != NULL) list->print(os, level);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        spec->generateMIPS(context, instructions);
        if (list != NULL) list->generateMIPS(context, instructions);
    }

protected:
    BaseNode *spec;
};

//************************************************************
//-----------------------DECLARATIONS-------------------------
//************************************************************

class InitDeclarator : public BaseNode {        //MIPS DONE  
public:
    InitDeclarator(BaseNode *_dec, BaseExpression *_init) : dec(_dec), init(_init) {}
    ~InitDeclarator() {
        delete dec;
        delete init;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Initialized Declarator:" << std::endl;
        dec->print(os, level+1);
        os << indent(level+1) << "=" << std::endl;
        init->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        context.declaration = false;
        dec->printPy(os, context);
        os << " = ";
        init->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (context.decFlags().init) {
            if (context.stack.size() == 1) {    // global scope

                instructions.push_back({".data", "", "", "", 0, Instruction::E});
                instructions.push_back({".global", context.tempDec.identifier, "", "", 0, Instruction::S});
                // .type   x, @object
                instructions.push_back({".type", context.tempDec.identifier, "@object", "", 0, Instruction::SS});
                instructions.push_back({"list_start","","","",0, Instruction::LIST});
                instructions.push_back({"label", context.tempDec.identifier, "", "", 0, Instruction::L});
                instructions.push_back({"list_end","","","",0, Instruction::LIST});
                instructions.push_back({" .word", "", "", "", (int)(init->eval()), Instruction::N});

            } else {                // not global scope
                int reg = context.chooseReg();
                context.pushToStack({reg}, instructions);
                init->generateMIPS(context, instructions, reg);
                context.writeStack(reg, context.varMap()[context.tempDec.identifier].offset, instructions);
                context.pullFromStack({reg}, instructions);
            }
        } else {
            dec->generateMIPS(context, instructions);
        }
    }

protected:
    BaseNode *dec;
    BaseExpression *init;
};

class InitDecList : public BaseList {           //MIPS DONE
public:
    InitDecList(BaseList *_list, BaseNode *_dec) : BaseList(_list), dec(_dec) {}
    ~InitDecList() {
        if (list != NULL) delete list;
        delete dec;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        dec->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) list->printPy(os, context);
        context.declaration = true;
        os << context.indentPy();
        dec->printPy(os, context);
        os << std::endl;
        context.declaration = false;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        dec->generateMIPS(context, instructions);
    }

protected:
    BaseNode *dec;
};

class TypeDefDecSpec : public BaseNode {        //MIPS DONE
public:
    TypeDefDecSpec(BaseNode *_decSpec) : decSpec(_decSpec) {}
    ~TypeDefDecSpec() { if (decSpec != NULL) delete decSpec; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "TypeDef Declaration:" << std::endl;
        if (decSpec != NULL) decSpec->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        context.tempDec.typeDef = true;
        if (decSpec != NULL) decSpec->generateMIPS(context, instructions);
    }

protected:
    BaseNode *decSpec;
};

class TypeSpecDecSpec : public BaseNode {       //MIPS DONE
public:
    TypeSpecDecSpec(BaseNode *_typeSpec, BaseNode *_decSpec) : typeSpec(_typeSpec), decSpec(_decSpec) {}
    ~TypeSpecDecSpec() {
        delete typeSpec;
        delete decSpec;
    }

    void print(std::ostream &os, int level) {
        typeSpec->print(os, level);
        decSpec->print(os, level);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        typeSpec->generateMIPS(context, instructions);
        decSpec->generateMIPS(context, instructions);
    }

protected:
    BaseNode *typeSpec, *decSpec;
};

class Declaration : public BaseNode {           //MIPS DONE  
public:
    Declaration(BaseNode *_decSpec, BaseList *_initDecList) : decSpec(_decSpec), initDecList(_initDecList) {}
    ~Declaration() {
        delete decSpec;
        delete initDecList;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declaration: " << std::endl;
        decSpec->print(os, level+1);
        os << indent(level+1) << "Declarator List:" << std::endl;
        initDecList->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        initDecList->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        for(int i = initDecList->size() - 1; i >= 0; --i) {
            context.tempDec = {};
            decSpec->generateMIPS(context, instructions);
            initDecList->at(i)->generateMIPS(context, instructions);
            if (context.tempDec.typeDef)
                context.typeMap()[context.tempDec.identifier] = context.tempDec.type;
            else {
                context.addDeclaration(instructions);
                context.decFlags().init = true;
                initDecList->at(i)->generateMIPS(context, instructions);    // runs second time for initialization
                context.decFlags().init = false;
            }
        }
    }

protected:
    BaseNode *decSpec;
    BaseList *initDecList;
};

#endif