int imagination(int a[5], int b, int c, int d, int e[2]){
    int i;
    for (i=0; i<5; i++){
        if(a[i] == 0)
            return 1;
    }
    if(b || c || d || e[0] || e[1])   return 1;
    return 0;
}

int* supplement(int array[2]){
    int i=0;
    while(i<2){
        array[i]--;
        i++;
    }
    return array;
}