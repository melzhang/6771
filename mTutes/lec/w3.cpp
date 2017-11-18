#include<iostream>

class Foo { 
public:
   static int g() { return 4; }
   Foo() : x(2) { }
   void print(int x);
   int getX() { return x;} 
private:
   int x;
};

int g() { return 3; }
 
void Foo::print(int x) { std::cout << ::g() << std::endl; }

int main(){
   Foo f;
   f.print(g());
   f.getX();
}