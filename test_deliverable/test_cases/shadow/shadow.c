
int func() {
	int x = 10;
	{
		int x = 5;
	}
	return x - 10;
}
