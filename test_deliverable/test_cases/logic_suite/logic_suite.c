int positive_check(){
    int op1 = -1, op2 = 4;
    return (op1 && op2) + (op1 || op2);
}

int negative_check(){
    int op1 = 0, op2 = 5;
    return (op1 && op2) + (op1 || op2);
}
//TODO: short circuiting checks with pointers