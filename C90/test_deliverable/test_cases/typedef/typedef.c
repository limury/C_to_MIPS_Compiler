
typedef int* test;

int func() {
	int x = 7;
	test a = &x;
	return *a - 2;
}
