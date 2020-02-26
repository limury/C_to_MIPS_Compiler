int lt();
int gt();

int main(){
	int a = lt();
	int b = gt();
	int c = lt() - gt();
    return a - b + c;
}
