int logicFunc(int a, int b, int c, int d)
{
    /* Tests:
    //parsing of multi-line comments
    /*tryna break it here
    function with 4 arguments
    */
    return a+b - c*d + 1; //0
}

int loopFunc(int a, int b){
    /* Tests:
    While loop
    If-Else
    */
   while(b < 5){
        if(b==10)   //never happens
            a = 50;
        else        //always happens
            b = b + 1;
   }
   return a;
}


int main()
{
    int var = 0;
    /* Tests:
    logical AND, logical OR
    comparison operators
    */
   int result = logicFunc(var,var,var,var) && loopFunc(var,0);
    return logicFunc(var, var, 1, 1) || result; //passed literals and variables
}

