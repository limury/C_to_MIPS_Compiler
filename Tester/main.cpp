#include <stdio.h>
#include <vector>
#include <iostream>


enum enumerator {first, second, third};

class foo {
  public:
    foo(int a, char b, enumerator l): alpha(a), beta(b), l(l){}
    int alpha;
    char beta;
    enumerator l;

};

typedef std::vector<int*> vectorized;

int main(){

    int* a;
    int* b;
    a = new int(10);
    b = new int(25);

    vectorized vec = {a, b};

    foo mave(1, 'a', third);

    std::cout << mave.alpha << " "<< mave.beta << " " <<mave.l ;

}

