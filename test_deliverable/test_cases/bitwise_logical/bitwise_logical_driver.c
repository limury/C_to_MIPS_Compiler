int or_check();
int and_check();
int xor_check();

int main(){
    return or_check() - and_check() + xor_check();
}