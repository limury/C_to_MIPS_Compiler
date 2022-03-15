int ref(){
    int var = 4;
    int* ptr = &var;
    *ptr = 1;

    return var;
}