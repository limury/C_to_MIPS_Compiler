#ifndef COMPCONTEXT_HPP
#define COMPCONTEXT_HPP

class BaseNode;         // forward declarations for context
class BaseExpression;

enum typeEnum {
    VOID_T,
    CHAR_T,
    SHORT_T,
    INT_T,
    LONG_T,
    FLOAT_T,
    DOUBLE_T,
    SIGNED_T,
    UNSIGNED_T,
    TYPEDEF_TYPE_T
}; 

const static std::map<typeEnum, std::string> typeStrings = {   // mainly for printing, will also be used in Type below
    {VOID_T, "void"},
    {CHAR_T, "char"},
    {SHORT_T, "short"},
    {INT_T, "int"},
    {LONG_T, "long"},
    {FLOAT_T, "float"},
    {DOUBLE_T, "double"},
    {SIGNED_T, "signed"},
    {UNSIGNED_T, "unsigned"}
};

struct Instruction {
    std::string name;
    std::string arg1, arg2, arg3;
    long int number;
    enum { SSS, SSN, SN, SS, S, N, LS, E, L, LIST, COMMENT } printMethod;  
    // LS = load/store
    // E = empty (nop)
    // L = label
    // D = dot (e.g. .text)
    // LIST = toggle new line
};

struct CompContext {
    std::string makeALabel(const std::string &str) {
        static int id = 0;
        return "_" + str + "_" + std::to_string(id++);
    }

    void addComment(std::vector<Instruction> &instr, const std::string &msg) {
        instr.push_back({msg, "", "", "", 0, Instruction::COMMENT});
    }

    struct Type {
        int pointerNum;
        std::vector< std::pair<typeEnum, std::string> > typeSpecifiers;     // this will hold types, string only for typedef types
        std::vector< int > arraySizes;                              // each element represents a new dimention

        int length() {                      // as multiple of 4     TODO: when doing chars, may need to change
            int ret = 4;
            if (pointerNum == 0)
                for (int i = 0; i < (int)arraySizes.size(); ++i)
                    ret *= arraySizes[i];
            return ret;
        }
    };
    
    struct varStruct {
        Type type; 
        int offset;
    };

    struct funcStruct {
        Type retType;
        std::vector< std::pair<std::string, Type> > params;
    };

    struct stackStruct {
        std::map<std::string, varStruct> varMap;
        std::map<std::string, Type> typeMap;
        struct decFlagStruct {
            bool functionDef, functionBody, init;
            std::string funcName;
        } decFlags;
        struct statementFlagStruct {
            bool indiCompound = true;
            std::string continueFlag, breakFlag;
			int cbOffset = 0;
        } statementFlags;
        struct switchFlagStruct {
            std::string defaultFlag;
            std::vector< std::pair<std::string, double> > caseFlags;
        } switchFlags;
        struct enumFlagStruct {
            int lastVal = -1;
        } enumFlags;
        struct funcCallFlagStruct {
            int argNum = 0;
        } funcCallFlags;

        int stackOffset;
    };

    std::map<std::string, funcStruct> funcMap;
    std::map<std::string, Type> globals;

    struct {
        bool typeDef;
        std::string identifier;
        Type type;
    } tempDec;                     // as declarations happen, info should be pushed into tempType (will be handled after in declaration node)

    std::vector<stackStruct> stack;         // to keep track of scopes and context

    //******* PASS THROUGHS ************
    std::map<std::string, varStruct>& varMap() { return stack.back().varMap; }
    std::map<std::string, Type>& typeMap() { return stack.back().typeMap; }
    stackStruct::decFlagStruct& decFlags() { return stack.back().decFlags; }
    stackStruct::statementFlagStruct& statementFlags() { return stack.back().statementFlags; }
    stackStruct::switchFlagStruct& switchFlags() { return stack.back().switchFlags; }
    stackStruct::enumFlagStruct& enumFlags() { return stack.back().enumFlags; }
    stackStruct::funcCallFlagStruct &funcCallFlags() { return stack.back().funcCallFlags; }
    funcStruct& currentFunc() { return funcMap[decFlags().funcName]; }
    //**********************************

    int memUsed = 0;

    int chooseReg(const std::vector<int> &regs = {}) {
        for (int i = $s0; ; ++i) {
            bool yes = true;
            for(int j = 0; j < regs.size(); ++j)
                if (regs[j] == i) yes = false;
            if (yes) return i;
        }
    }

    void printRetSequence(std::vector<Instruction> &instructions) {
        readStack($ra, 4, instructions);
        readStack($fp, 8, instructions);
        //instructions.push_back({"addi", regMap[$sp], regMap[$fp], "", 0, Instruction::SSN});   // move $sp to $fp
        instructions.push_back({"addiu", regMap[$sp], regMap[$sp], "", memUsed, Instruction::SSN});
        instructions.push_back({"jr", regMap[$ra], "", "", 0, Instruction::S}); // jump back to return address
    }

    bool local(const std::string &str) {
        return (varMap().find(str) != varMap().end());
    }

    bool param(const std::string &str) {
        for(int i = 0; i < currentFunc().params.size(); ++i) {
            if (currentFunc().params[i].first == str)
                return true;
        }
        return false;
    }

    void pushToStack(const std::vector<int> &reg, std::vector<Instruction> &instructions) {
        for(int i = 0; i < (int)reg.size(); ++i) {
            memUsed += 4;                   // increment then store
			instructions.push_back({"Pushing " + regMap[reg[i]] + " to stack", "", "", "", 0, Instruction::COMMENT});
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", -4, Instruction::SSN});
            instructions.push_back({"sw", regMap[reg[i]], regMap[$sp], "", 0, Instruction::LS});
        }
    }

    void pullFromStack(const std::vector<int> &reg, std::vector<Instruction> &instructions) {
        for(int i = 0; i < (int)reg.size(); ++i) {      
			instructions.push_back({"Pulling " + regMap[reg[i]] + " from stack", "", "", "", 0, Instruction::COMMENT});
            instructions.push_back({"lw", regMap[reg[i]], regMap[$sp], "", 0, Instruction::LS});
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", 4, Instruction::SSN});
            memUsed -= 4;           // read then decrement
        }
    }

    void writeGlobal(int reg, std::string label, std::vector<Instruction> &instructions, int offset = 0){
        int tempReg = chooseReg({reg});
        pushToStack({tempReg}, instructions);
        instructions.push_back({"li", regMap[tempReg], label, "", 0, Instruction::SS});
        instructions.push_back({"sw", regMap[reg], regMap[tempReg], "", offset, Instruction::LS});
        pullFromStack({tempReg}, instructions);
    }

    void readGlobal(int reg, std::string label, std::vector<Instruction> &instructions, int offset = 0){
        instructions.push_back({"li", regMap[reg], label, "", 0, Instruction::SS});
        instructions.push_back({"lw", regMap[reg], regMap[reg], "", offset, Instruction::LS});
    }

    void writeStack(int reg, int offset, std::vector<Instruction> &instructions) {
        int spOffset = memUsed - offset;
        instructions.push_back({"sw", regMap[reg], regMap[$sp], "", spOffset, Instruction::LS});
    }

    void readStack(int reg, int offset, std::vector<Instruction> &instructions) {
        int spOffset = memUsed - offset;
        instructions.push_back({"lw", regMap[reg], regMap[$sp], "", spOffset, Instruction::LS});
    }

    void addDeclaration(std::vector<Instruction> &instructions) {
        addComment(instructions, "Allocating " + std::to_string(tempDec.type.length()) + " for " + tempDec.identifier);
        if (stack.size() != 1) {    // in global scope
            int length = tempDec.type.length();
            memUsed += length;
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", -length, Instruction::SSN});
            stack.back().varMap[tempDec.identifier] = {tempDec.type, memUsed};
        } else {
            globals[tempDec.identifier] = tempDec.type;
        }
    }

    void addCustomDec(const std::string &iden, Type type, std::vector<Instruction> &instructions) {
        if (stack.size() != 1) {    // in global scope
            int length = type.length();
            int offset = memUsed + 4;
            for (int i = 0; i < length; i += 4) {
                memUsed += 4;
                instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", -4, Instruction::SSN});
            }
            stack.back().varMap[iden] = {type, offset};
        } else {
            globals[iden] = type;
        }
    }

    void addScopeContext() {
        if (stack.size() > 0) {
            stack.push_back(stack.back());
            stack.back().stackOffset = memUsed;     // record location of the stack
        } else {
            stack.push_back({});
        }
    }

    void subScopeContext() {
        stack.pop_back();
    }

    void addScope(std::vector<Instruction> &instructions) {
        if (stack.size() > 0) {
            stack.push_back(stack.back());
            stack.back().stackOffset = memUsed;     // record location of the stack
        } else {
            stack.push_back({});
        }
    }

    void subScope(std::vector<Instruction> &instructions) {
        int offset = memUsed - stack.back().stackOffset;
        memUsed = stack.back().stackOffset;
        instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", offset, Instruction::SSN});   // push $sp back to where it was
        stack.pop_back();
    }

    void addScopeFunc(std::vector<Instruction> &instructions) {
        addScopeContext();

        instructions.push_back({".text", "", "", "", 0, Instruction::E});
        instructions.push_back({".global", stack.back().decFlags.funcName, "", "", 0, Instruction::S});
        instructions.push_back({".ent", stack.back().decFlags.funcName, "", "", 0, Instruction::S});
        instructions.push_back({".type", stack.back().decFlags.funcName, "@function", "", 0, Instruction::SS});
        instructions.push_back({"label", stack.back().decFlags.funcName, "", "", 0, Instruction::L});

        // store up to 4 function args on the prev stack frame
        for (int reg = $4, offset = 0; offset < (int)funcMap[decFlags().funcName].params.size()*4 && offset < 16; ++reg, offset += 4 ) {
            writeStack(reg, memUsed - offset, instructions);
        }

        pushToStack({$ra, $fp}, instructions);
    }

    void subScopeFunc(std::vector<Instruction> &instructions) {
        instructions.push_back({"addi", regMap[$2], regMap[$0], "", 0, Instruction::SSN});
        printRetSequence(instructions);
        instructions.push_back({".end", stack.back().decFlags.funcName, "", "", 0, Instruction::S});
        memUsed = 0;
        subScopeContext();
    }

    Type& currentType(std::string identifier) {
        Type *type = NULL;
        if (local(identifier)) {    //local
            type = &varMap()[identifier].type;
        } else if (param(identifier)) {
            for(int i = 0; i < currentFunc().params.size(); i++){
                if (currentFunc().params[i].first == identifier) { // param
                    type = &currentFunc().params[i].second;
                    break;
                }
            }
        } else {        // global
            type = &globals[identifier];
        }
        return *type;
    }

    int arrayNum = 0;
    int currentArrMult = 4;
};

#endif

