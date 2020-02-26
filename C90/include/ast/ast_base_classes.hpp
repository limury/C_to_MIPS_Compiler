#ifndef AST_BASE_CLASSES_HPP
#define AST_BASE_CLASSES_HPP

class BaseNode : public AST {
public:
    virtual void structInspect(CompContext &context) {}
protected:
};

class BaseList : public AST {
public:
    BaseList(BaseList *_list) : list(_list) {}
    virtual ~BaseList() {
        if (list != NULL)
            delete list;
    }

    int size() {
        if (list != NULL)
            return 1 + list->size();
        else 
            return 1;
    }

    BaseList* at(int i) {       // iterates from the back
        if (i == 0)
            return this;
        else if (list != NULL)
            return list->at(i-1);
        else
            return NULL;
    }

    virtual void structInspect(CompContext &context) {}

protected:
    BaseList *list;
};

class BaseExpression : public AST {
public:
    virtual double eval() { return 0; }
    virtual void address(int destReg, CompContext &context, std::vector<Instruction> &instructions) {}
    virtual void arrayOffset(int destReg, CompContext &context, std::vector<Instruction> &instructions) {
        context.arrayNum = 0; 
        context.currentArrMult = 4;
        instructions.push_back({"li", regMap[destReg], "", "", 0, Instruction::SN});
    }
    virtual void getPointerVal(int destReg, CompContext &context, std::vector<Instruction> &instructions) {}
    virtual bool isPointer(CompContext &context) { return false; }
    virtual std::string getIdentifier() { return ""; }
    virtual int length(CompContext &context) { return 4; }
protected:
};

class BaseExpressionList : public AST {
public:
    BaseExpressionList(BaseExpressionList *_list) : list(_list) {}
    virtual ~BaseExpressionList() {
        if (list != NULL)
            delete list;
    }

    int size() {
        if (list != NULL)
            return 1 + list->size();
        else 
            return 1;
    }

    BaseExpressionList* at(int i) {
        if (i == 0)
            return this;
        else if (list != NULL)
            return list->at(i-1);
        else
            return NULL;
    }

    virtual double eval() { return 0; }

protected:
    BaseExpressionList *list;
};

#endif