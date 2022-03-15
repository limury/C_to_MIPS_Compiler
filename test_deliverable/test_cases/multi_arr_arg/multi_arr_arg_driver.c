
void func(int array[10][10]);

int main() {
    int array[10][10];
    func(array);
    return array[1][2] - 5;
}