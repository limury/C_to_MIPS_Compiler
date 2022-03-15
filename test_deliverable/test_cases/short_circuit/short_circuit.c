int short_or(){
    int* x = 0;
    int y = 1;
    return (y || *x);
}

int short_and(){
    int* x = 0;
    return (x && *x);
}