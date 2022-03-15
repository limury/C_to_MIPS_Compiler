
int func() {
	int x;
	return sizeof(x);
}

int func2() {
	return sizeof(3+2);
}

int func3() {
	int x[5];
	return sizeof(x);
}
