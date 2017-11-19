#include <iostream>

// Q: The assignment b = d; is legal but is poor style as it causes the object slicing problem. What is the object slicing problem?
// A: obj slicing, is when sub-class properties are discarded
// Q: What is the output of b.f(); and why is this output produced?
// A: "B" as it is the base class function call, after class D was sliced
// Q: What is the output of pb.f(); and why is this output produced?
// A: pb is class B, which will output B, as it a reference to variable b
// Q: How can we correct this code to prevent the object slicing problem?
// A: by using pointers or references

/*
We can avoid above unexpected behavior with the use of pointers or references. Object slicing doesn’t occur when pointers or references to objects are passed as function arguments since a pointer or reference of any type takes same amount of memory. For example, if we change the global method f() in the program to following, object slicing doesn’t happen.
*/

class B {
public:
  virtual void f() {
    std::cout << "B ";
  }
};

class D : public B {
public:
  using B::f; // for hidden case, ie if D failed; B function would be used
  virtual void f() {
    std::cout << "D ";
  }
};

int main() {
  D *d = new D();
  B *b = d;
  B &pb = *b;
  b->f();
  pb.f();
  d->f();
}
