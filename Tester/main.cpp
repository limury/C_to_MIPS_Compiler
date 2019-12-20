#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Shape{
  public:
    int width, height;
    Shape(int a = 0, int b = 0): width(a), height(b){}
    virtual int printArea() {
        cout << "Shape class area: %d\n";
        return -1;
    }
};
class Rectangle: public Shape {
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b), test("This means you can morph") { }
      string test;
      int printArea () { 
         cout << "Rectangle class area :" << test <<endl;
         return (width * height); 
      }
};


int main(){

    int* a;
    a = nullptr;
    if (!a){
        printf("Nullptr\n");
    }

}

