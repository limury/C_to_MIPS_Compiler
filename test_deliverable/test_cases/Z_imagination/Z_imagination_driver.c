int imagination(int a[5], int b, int c, int d, int e[2]);
int* supplement(int array[2]);

int main(){
    int a[5] = {1,2,3,4,5};
    int b,c,d;
    b = c = d = 0;
    int e[2] = {1,1};
    return imagination(a,b,c,d,supplement(e));
}
