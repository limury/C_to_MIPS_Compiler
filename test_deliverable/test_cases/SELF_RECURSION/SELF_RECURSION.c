
int func(int num) {
    int x;
    if (num == 0) {
        return 0;
    }
    x = func(num - 1);
    return x;
}