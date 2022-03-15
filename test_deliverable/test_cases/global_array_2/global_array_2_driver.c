
extern int x[10];
void func(int num);

int main() {
	x[1] = 5;
	func(10);
	return x[1] - 10;
}
