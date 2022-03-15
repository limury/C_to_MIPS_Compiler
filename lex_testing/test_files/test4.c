int x;

enum test {
    hello,
    there
};

typedef struct {
    struct {
        enum {
            TEST1
        } test;
        int test2;
    } nested;
} testTYPE;

int main() {
    testTYPE str1 = {{TEST1, 2}};
}
