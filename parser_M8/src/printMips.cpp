#include "../include/Node.hpp"
#include "../include/Context.hpp"

using namespace std;

void printMips (vector<Instruction>& instr, Context& cont, NodePtr ast, bool new_scope=false);

std::string printMipsWrapper(NodePtr ast){

    Context context;
    vector<Instruction> instructions;
    
    printMips(instructions, context, ast);
    
}


void printMips (vector<Instruction>& instr, Context& cont, NodePtr ast, bool new_scope=false){

    if (new_scope) {
        Context context = cont;

        switch(ast->type){
            case primary_expression:
                
        }


    }
    else {
        Context& context = cont;
    }

}