int not();
int negation();
int inversion();

int main(){
    return not(0) + negation(-1) - inversion(0xfffffffd);
}
