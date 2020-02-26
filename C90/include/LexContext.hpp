#ifndef LEXCONTEXT_HPP
#define LEXCONTEXT_HPP

#include <iostream>
#include <vector>

struct LexContext {

    struct info {
        std::vector<std::string> typeDef;
        std::vector<std::string> Enum;
        bool typeDefActive = false;
        bool declarationActive = false;
        bool ignoreIdentifier = false;
    };

    std::vector<info> stack = {{}};

    int scopeLevel = 0;

    bool typeDefed(const std::string& str) {
        for(int i = 0; i < (int)stack.back().typeDef.size(); i++) {
            if (stack.back().typeDef[i] == str)
                return true;
        }
        return false;
    }
    bool findAndDestroyTD(const std::string& str) {
        for(auto i = stack.back().typeDef.begin(); i != stack.back().typeDef.end(); ++i) {
            if (*i == str) {
                stack.back().typeDef.erase(i);
                return true;
            }
        }
        return false;
    }

    void addScope() {
        scopeLevel++;
        stack.push_back(stack.back());
        stack.back().typeDefActive = false;
        stack.back().declarationActive = false;
        stack.back().ignoreIdentifier = false;
    }
    void subScope() {
        scopeLevel--;
        stack.pop_back();
    }

    std::string currentName;

    bool declarationActive() { return stack.back().declarationActive; }
    bool typeDefActive() { return stack.back().typeDefActive; }
    bool ignoreIdentifier() { return stack.back().ignoreIdentifier; } 

    void declarationActive(bool cond) { 
        stack.back().declarationActive = cond; 
    }   
    void typeDefActive(bool cond) { 
        stack.back().typeDefActive = cond; 
    }
    void ignoreIdentifier(bool cond) { 
        stack.back().ignoreIdentifier = cond; 
    } 

    void addTypeDef(const std::string& str) {
        stack.back().typeDef.push_back(str);
    }
};

#endif