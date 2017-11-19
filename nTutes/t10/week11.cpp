/*
topics:
Inheritance
Polymorphism
Access Control
Vtables
*/

class Base {
public:
  const int& getI() const { return i; }
private:
  int i;
};

// A: initial class won't compile because i is private, changing it to protected
// allows Inheritance - cons: has a coupling of base to Inheritance
// A: we change it such that getI is a getter of the base class:
// this allows us to decouple the dependencies
class Derived : public Base {
public:
  void foo(Derived &o) {
    j = o.getI() + o.j;
  }
private:
  int j;
};

int main() {
  return 0;
}
