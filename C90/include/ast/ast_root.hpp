#ifndef AST_NODE_HPP
#define AST_NODE_HPP

class AST {
public:

    static std::string indent(int num) {
        if (num == 0)
            return "";
        else
            return indent(num-1) + "\t|";
    }
    
    virtual ~AST() {}
    virtual void print(std::ostream& os, int level) {}
    virtual void printPy(std::ostream &os, PyContext &context) {}
    virtual void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {}
protected:
};

#endif