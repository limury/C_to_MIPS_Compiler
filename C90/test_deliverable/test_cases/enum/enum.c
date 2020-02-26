
int func() {
    enum {
        E1 = 3,
        E2,
        E3
    } enumTest;
    enumTest = E3;
    return enumTest;
}
