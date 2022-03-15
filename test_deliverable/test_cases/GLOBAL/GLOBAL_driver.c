
extern int x;
int func(int num);

int main() {
	int num = 10;
	func(num);
	return x - num;
}
