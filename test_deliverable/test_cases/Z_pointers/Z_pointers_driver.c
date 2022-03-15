void imagination(int* ptr[5]);

int main(){
    int a,b,c,d,e;
    a=b=c=d=e=1;
    int* vars[5] = {&a,&b,&c,&d,&e};    //array of pointers to five '1's
    
    imagination(vars);          //seg faults inside function
    
    int i, result=0;
    for(i=0; i<5; i++){
        result += *(vars[i]);   //add them all into an accumulator variable and result should be zero
    }
    
    return result;
}