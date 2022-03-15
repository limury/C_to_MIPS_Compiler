
int func2(int num);

int func(int num) {
    if (num == 0)
        return 0;
    return func2(num - 1);
}

int func2(int num) {
    if (num == 0)
        return 0;
    return func(num - 1);
}
