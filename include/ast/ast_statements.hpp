#ifndef AST_STATEMENTS_HPP
#define AST_STATEMENTS_HPP

//************************************************************
//---------------------JUMP STATEMENT-------------------------
//************************************************************

class Continue : public BaseNode {                  
public:
    Continue() {}
    ~Continue() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Continue" << std::endl;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
		//TODO: de-allocate stack
		int offset = context.memUsed - context.statementFlags().cbOffset;
        instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", offset, Instruction::SSN});
        instructions.push_back({"j", context.statementFlags().continueFlag, "", "", 0, Instruction::S});
    }

protected:
};

class Break : public BaseNode {                     
public:
    Break() {}
    ~Break() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Break" << std::endl;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
		//TODO: de-allocate stack
		int offset = context.memUsed - context.statementFlags().cbOffset;
        instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", offset, Instruction::SSN});
        instructions.push_back({"j", context.statementFlags().breakFlag, "", "", 0, Instruction::S});
    }
    
protected:
};

class Return : public BaseNode {                     
public:
    Return(BaseExpression *_expr) : expr(_expr) {}
    ~Return() { if (expr != NULL) delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Return:" << std::endl;
        if (expr != NULL)
            expr->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "return ";
        if (expr != NULL)
            expr->printPy(os, context);
        os << std::endl;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (expr == NULL) {
            instructions.push_back({"addi", regMap[$2], regMap[$0], "", 0, Instruction::SSN});
        } else {
            expr->generateMIPS(context, instructions, $2);
        }
        context.printRetSequence(instructions);
    }
    
protected:
    BaseExpression *expr;
};

//************************************************************
//-------------------ITERATION STATEMENT----------------------
//************************************************************

class WhileLoop : public BaseNode {                 
public:
    WhileLoop(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~WhileLoop() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "While Loop:" << std::endl;
        os << indent(level+1) << "Condition:" << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "while ";
        expr->printPy(os, context);
        os << ":" << std::endl;
        context.addScope();
        statement->printPy(os, context);
        context.subScope();
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
		instructions.push_back({"Entering while loop", "", "", "", 0, Instruction::COMMENT});
        int reg = $2;
        context.addScopeContext();
		context.statementFlags().cbOffset = context.stack.back().stackOffset;
        context.statementFlags().continueFlag = context.makeALabel("continue");
        context.statementFlags().breakFlag = context.makeALabel("break");
        instructions.push_back({"label", context.statementFlags().continueFlag, "", "", 0, Instruction::L});
        expr->generateMIPS(context, instructions, reg);
        instructions.push_back({"beq", regMap[reg], regMap[$0], context.statementFlags().breakFlag, 0, Instruction::SSS});
		
        statement->generateMIPS(context, instructions);

        instructions.push_back({"j", context.statementFlags().continueFlag, "", "", 0, Instruction::S});
        instructions.push_back({"label", context.statementFlags().breakFlag, "", "", 0, Instruction::L});
        context.subScopeContext();
		instructions.push_back({"Exiting while loop", "", "", "", 0, Instruction::COMMENT});
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

class DoWhileLoop : public BaseNode {                    
public:
    DoWhileLoop(BaseNode *_statement, BaseExpression *_expr) : statement(_statement), expr(_expr) {}
    ~DoWhileLoop() {
        delete statement;
        delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Do While Loop:" << std::endl;
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
        os << indent(level+1) << "Condition:" << std::endl;
        expr->print(os, level+2);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int reg = $2;
        context.addScopeContext();
		context.statementFlags().cbOffset = context.stack.back().stackOffset;

        context.statementFlags().continueFlag = context.makeALabel("continue");
        context.statementFlags().breakFlag = context.makeALabel("break");

        instructions.push_back({"label", context.statementFlags().continueFlag, "", "", 0, Instruction::L});

        statement->generateMIPS(context, instructions);

        expr->generateMIPS(context, instructions, reg);
        instructions.push_back({"bne", regMap[reg], regMap[$0], context.statementFlags().continueFlag, 0, Instruction::SSS});
        instructions.push_back({"label", context.statementFlags().breakFlag, "", "", 0, Instruction::L});

        context.subScopeContext();
    }

protected:
    BaseNode *statement;
    BaseExpression *expr;
};

class ForLoop : public BaseNode {                   
public:
    ForLoop(BaseExpression *_expr1, BaseExpression *_expr2, BaseExpression *_expr3, BaseNode *_statement) : expr1(_expr1), expr2(_expr2), expr3(_expr3), statement(_statement)  {}
    ~ForLoop() {
        if (expr1 != NULL) delete expr1;
        if (expr2 != NULL) delete expr2;
        if (expr3 != NULL) delete expr3;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "For Loop:" << std::endl;
        if (expr1 != NULL) {
            os << indent(level+1) << "Expression 1:" << std::endl;
            expr1->print(os, level+2);
        }
        if (expr2 != NULL) {
            os << indent(level+1) << "Expression 2:" << std::endl;
            expr2->print(os, level+2);
        }
        if (expr3 != NULL) {
            os << indent(level+1) << "Expression 3:" << std::endl;
            expr3->print(os, level+2);
        }
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int reg = $2;
        context.addScopeContext();
		context.statementFlags().cbOffset = context.stack.back().stackOffset;
        context.statementFlags().continueFlag = context.makeALabel("continue");
        context.statementFlags().breakFlag = context.makeALabel("break");

        if (expr1 != NULL) expr1->generateMIPS(context, instructions, reg);
        instructions.push_back({"label", context.statementFlags().continueFlag, "", "", 0, Instruction::L});
        if (expr2 != NULL) {
            expr2->generateMIPS(context, instructions, reg);
            instructions.push_back({"beq", regMap[reg], regMap[$0], context.statementFlags().breakFlag, 0, Instruction::SSS});
        }

        statement->generateMIPS(context, instructions);

        if (expr3 != NULL) expr3->generateMIPS(context, instructions, reg);
        instructions.push_back({"j", context.statementFlags().continueFlag, "", "", 0, Instruction::S});
        instructions.push_back({"label", context.statementFlags().breakFlag, "", "", 0, Instruction::L});

        context.subScopeContext();
    }

protected:
    BaseExpression *expr1, *expr2, *expr3;
    BaseNode *statement;
};

//************************************************************
//-------------------SELECTION STATEMENT----------------------
//************************************************************

class IfStatement : public BaseNode {               
public:
    IfStatement(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~IfStatement() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "If Statement:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body: " << std::endl;
        statement->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "if ";
        expr->printPy(os, context);
        os << ":" << std::endl;
        context.addScope();
        statement->printPy(os, context);
        context.subScope();
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        std::string falseLabel = context.makeALabel("false");
        int reg = $2;
        context.addComment(instructions, "If statement: temp reg = " + regMap[reg]);
        expr->generateMIPS(context, instructions, reg);
        instructions.push_back({"beq", regMap[reg], regMap[$0], falseLabel, 0, Instruction::SSS});
        statement->generateMIPS(context, instructions);
        instructions.push_back({"lebel", falseLabel, "", "", 0, Instruction::L});
        context.addComment(instructions, "Exiting if statement...");
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

class IfElseStatement : public BaseNode {           
public:
    IfElseStatement(BaseExpression *_expr, BaseNode *_statementTrue, BaseNode *_statementFalse) : expr(_expr), statementTrue(_statementTrue), statementFalse(_statementFalse) {}
    ~IfElseStatement() {
        delete expr;
        delete statementTrue;
        delete statementFalse;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "If Else Statement:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "True Body: " << std::endl;
        statementTrue->print(os, level+2);
        os << indent(level+1) << "False Body: " << std::endl;
        statementFalse->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "if ";
        expr->printPy(os, context);
        os << ":" << std::endl;
        context.addScope();
        statementTrue->printPy(os, context);
        context.subScope();
        os << context.indentPy() << "else:" << std::endl;
        context.addScope();
        statementFalse->printPy(os, context);
        context.subScope();
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        std::string trueLabel = context.makeALabel("true");
        std::string falseLabel = context.makeALabel("false");
        int reg = $2;
        expr->generateMIPS(context, instructions, reg);
        instructions.push_back({"beq", regMap[reg], regMap[$0], falseLabel, 0, Instruction::SSS});
        statementTrue->generateMIPS(context, instructions);
        instructions.push_back({"j", trueLabel, "", "", 0, Instruction::S});
        instructions.push_back({"label", falseLabel, "", "", 0, Instruction::L});
        statementFalse->generateMIPS(context, instructions);
        instructions.push_back({"label", trueLabel, "", "", 0, Instruction::L});
    }

protected:
    BaseExpression *expr;
    BaseNode *statementTrue, *statementFalse;
};

class SwitchStatement : public BaseNode {           
public:
    SwitchStatement(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~SwitchStatement() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Switch Statement:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body: " << std::endl;
        statement->print(os, level+2);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        context.switchFlags() = {};
        context.statementFlags().breakFlag = context.makeALabel("break");
        context.addScopeContext();
		context.statementFlags().cbOffset = context.stack.back().stackOffset;
        statement->structInspect(context);

        int expReg = $2, caseReg = $3;
        expr->generateMIPS(context, instructions, expReg);

        for (int i = 0; i < (int)context.switchFlags().caseFlags.size(); ++i) {
            instructions.push_back({"addi", regMap[caseReg], regMap[expReg], "", -(int)context.switchFlags().caseFlags[i].second, Instruction::SSN});   // for now only int
            instructions.push_back({"beq", regMap[caseReg], regMap[$zero], context.switchFlags().caseFlags[i].first, 0, Instruction::SSS});
        }

        if (context.switchFlags().defaultFlag != "") {          // only branch to default if there is one
            instructions.push_back({"j", context.switchFlags().defaultFlag, "", "", 0, Instruction::S});
        }

        statement->generateMIPS(context, instructions);         // should now print instructions

        instructions.push_back({"label", context.statementFlags().breakFlag, "", "", 0, Instruction::L});

        context.subScopeContext();
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

//************************************************************
//------------------EXPRESSION STATEMENT----------------------
//************************************************************

class ExpressionStatement : public BaseNode {       
public:
    ExpressionStatement(BaseExpression *_expr) : expr(_expr) {}
    ~ExpressionStatement() { if (expr != NULL) delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Expression Statement:" << std::endl;
        if (expr != NULL)
            expr->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (expr != NULL) {
            os << context.indentPy();
            expr->printPy(os, context);
            os << std::endl;
        }
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int reg = $2;
        if (expr != NULL)  expr->generateMIPS(context, instructions, reg);
    }

protected:
    BaseExpression *expr;
};

//************************************************************
//---------------------STATEMENT LIST-------------------------
//************************************************************

class StatementList : public BaseList {             
public:
    StatementList(BaseList *_list, BaseNode *_statement) : BaseList(_list), statement(_statement) {}
    ~StatementList() {
        if (list != NULL) delete list;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        statement->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) list->printPy(os, context);
        statement->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (list != NULL) list->generateMIPS(context, instructions);
        statement->generateMIPS(context, instructions);
    }

    virtual void structInspect(CompContext &context) {
        if (list != NULL) list->structInspect(context);
        statement->structInspect(context);
    }

protected:
    BaseNode *statement;
};

//************************************************************
//-------------------COMPOUND STATEMENT-----------------------
//************************************************************

class CompoundStatement : public BaseNode {         
public: 
    CompoundStatement(BaseList *_dec, BaseList *_state) : declarationList(_dec), statementList(_state) {}
    ~CompoundStatement() {
        if (declarationList != NULL) delete declarationList;
        if (statementList != NULL) delete statementList;
    }

    void print(std::ostream &os, int level) {
        if (declarationList != NULL) declarationList->print(os, level);
        if (statementList != NULL) statementList->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (declarationList != NULL) declarationList->printPy(os, context);
        if (statementList != NULL) statementList->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        bool indi = context.statementFlags().indiCompound;
        context.statementFlags().indiCompound = true;
        if (indi) context.addScope(instructions);
        if (declarationList != NULL) declarationList->generateMIPS(context, instructions);
        if (statementList != NULL) statementList->generateMIPS(context, instructions);
        if (indi) context.subScope(instructions);
    }

    void structInspect(CompContext &context) {
        if (statementList != NULL) statementList->structInspect(context);
    }

protected:
    BaseList *declarationList, *statementList;
};

//************************************************************
//--------------------LABLED STATEMENT------------------------
//************************************************************

class CaseBlock : public BaseNode {                 
public:
    CaseBlock(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~CaseBlock() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Case Block:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //vec elements will be deleted so just work with element 0
        instructions.push_back({"label", context.switchFlags().caseFlags[0].first, "", "", 0, Instruction::L});
        context.switchFlags().caseFlags.erase(context.switchFlags().caseFlags.begin());
        bool indi = context.statementFlags().indiCompound;
        context.statementFlags().indiCompound = true;
        statement->generateMIPS(context, instructions);
        context.statementFlags().indiCompound = indi;
    }

    void structInspect(CompContext &context) {
        std::string label = context.makeALabel("case");
        context.switchFlags().caseFlags.push_back({label, expr->eval()});
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

class DefaultCaseBlock : public BaseNode {          
public:
    DefaultCaseBlock(BaseNode *_statement) : statement(_statement) {}
    ~DefaultCaseBlock() { delete statement; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Default Case Block:" << std::endl;
        statement->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        instructions.push_back({"label", context.switchFlags().defaultFlag, "", "", 0, Instruction::L});
        bool indi = context.statementFlags().indiCompound;
        context.statementFlags().indiCompound = true;
        statement->generateMIPS(context, instructions);
        context.statementFlags().indiCompound = indi;
    }

    void structInspect(CompContext &context) {
        context.switchFlags().defaultFlag = context.makeALabel("default");
    }

protected:
    BaseNode *statement;
};

#endif
