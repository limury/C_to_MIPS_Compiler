#include <vector>
#include <iostream>
#include <fstream>

#include "ast.hpp"

bool needsNop(const std::string &name) {
    std::vector<std::string> things = {
        "beq",
        "bne",
        "bltz",
        "bltzal",
        "bgez",
        "bgezal",
        "bgtz",
        "blez",
        "j",
        "jal",
        "jr",
        "jalr",
        "lw",
        "lb",
        "lh"
    };
    for (int i = 0; i < things.size(); ++i)
        if (things[i] == name) return true;
    return false;
}

void printVec(std::ostream &os, const std::vector<Instruction> &instr) {            //TODO: nops need to be inserted correctly
    bool newLines = true;
    for (int i = 0; i < (int)instr.size(); ++i) {
        switch(instr[i].printMethod) {
            case Instruction::SSS:
                os << instr[i].name << " " << instr[i].arg1 << ", " << instr[i].arg2 << ", " << instr[i].arg3;
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::SSN:
                os << instr[i].name << " " << instr[i].arg1 << ", " << instr[i].arg2 << ", " << instr[i].number;
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::SN:
                os << instr[i].name << " " << instr[i].arg1 << ", " << instr[i].number;
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::SS:
                os << instr[i].name << " " << instr[i].arg1 << ", " << instr[i].arg2;
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::S:
                os << instr[i].name << " " << instr[i].arg1;
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::N:
                os << instr[i].name << " " << instr[i].number;
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::LS:
                os << instr[i].name << " " << instr[i].arg1 << ", " << instr[i].number << "(" << instr[i].arg2 << ")";
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::E:
                if (instr[i].name != "nop" && newLines)
                    os << std::endl;
                os << instr[i].name;
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::L:
                os << std::endl;
                os << instr[i].arg1 << ":";
                if (newLines) os << std::endl;
                if (needsNop(instr[i].name)) os << "nop" << std::endl;
                break;
            case Instruction::LIST:
                newLines = !newLines;
                break;
            case Instruction::COMMENT:
                os << "# " << instr[i].name << std::endl;
                break;
        }
    }
}

void translate(AST *tree, std::ostream &os) {
    PyContext context;
    tree->printPy(os, context);
}

void compile(AST *tree, std::ostream &os) {
    CompContext context;
    std::vector<Instruction> instructions;
    tree->generateMIPS(context, instructions);
    printVec(os, instructions);
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Not enough arguments passed." << std::endl;
        exit(10);
    }

    AST* ast;
    if (argc < 3) {
        std::cerr << "No input file specified. Using stdin." << std::endl;
        ast = parseAST();
    } else {
        ast = parseAST(argv[2]);
    }

    std::ostream* os = &std::cout;
    std::ofstream tempStrm;
    if (argc > 4) {
        tempStrm.open(argv[4]);
        if (tempStrm.is_open())
            os = &tempStrm;
        else
            std::cerr << "Cannot open output file... Printing to stdout." << std::endl;
    }

    if (std::string(argv[1]) == "-S")
        compile(ast, *os);
    else if (std::string(argv[1]) == "--translate")
        translate(ast, *os);

    tempStrm.close();

    return 0;
}