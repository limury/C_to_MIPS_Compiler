#include <map>
#include <iostream>
#include <string>

class cont {
    public:
    int a;
};

void function(cont& var){
    cont& var2 = var;
    var2.a = 5;

}

int main(){
    
    cont var;
    var.a = 2;
    function(var);
    std::cout << var.a << std::endl;

}