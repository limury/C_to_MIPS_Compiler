
int func2(int num) {
    return num;
}

int func() {
    return func2(func2(5));
}
