void imagination(int* ptr[5]){   
//subtracts 1 from each element using unnecessarily verbose pointer arithmetic and dereferencing
    int i;
    for(i=0; i<5; i++){
        //*(*(ptr+i)) = *(*(ptr+i)) - 1; //doesn't seg fault if you comment this out
        (*(*(ptr+i)))--;                //alternate version
    }
    return;
}
