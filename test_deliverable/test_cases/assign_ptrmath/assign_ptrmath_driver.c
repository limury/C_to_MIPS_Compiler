int* assignplus(int* ptr);
int* assignsub(int* ptr);

int main(){
    int x, y;
    int* ptr = &x;
    x = (int)(ptr + 8);
    y = (int)(ptr - 4);
    
    return (int)assignsub((int*)x) - (int)assignplus((int*)y);
}
