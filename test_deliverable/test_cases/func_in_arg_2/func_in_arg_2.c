
int func2(int a, int b) {
	return a + b;
}

int func() {
	return func2(func2(1,2), func2(3,4));
}
