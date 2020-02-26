int* ptrAdd(int* ptr);
int* ptrSub(int* ptr);

int main(){
    int* ptr;
    int x = 0;
    int y = 0;
    
    ptr = &x;
    x = ptr - 8;
    y = ptr + 4;
    return (int)ptrSub(y) - (int)ptrAdd(x);
}