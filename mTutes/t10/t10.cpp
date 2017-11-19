// class Base {
// protected:
//   int i;
// };
// // The code will now compile, but what are the potential disadvantages of this solution? 
// // derived can alter the base class

// class Derived : public Base {
// public:
//   void foo(Derived &o) {
//     j = o.i + o.j;
//   }
// private:
//   int j;
// };

// class Base {
// public:
//    const int& getI() const { return i; }
// private:
//   int i;
// };

// class Derived : public Base {
// public:
//   void foo(Derived &o) {
//     j = o.getI() + o.j;
//   }
// private:
//   int j;
// };
// What benefits does this approach give us? Why do we return a const reference to i?
// this way i can't be changed by the derived class

#include <iostream>

class B {
public:
  virtual void f() { 
    std::cout << "B "; 
  }
};

class D : public B {
public:
  virtual void f() override { 
    std::cout << "D "; 
  }
};

int main() {
  B b;
  D d;
  b = d;
  B &pb = b;
  b.f();
  pb.f();
}

// The assignment b = d; is legal but is poor style as it causes the object slicing problem. What is the object slicing problem?
// where a derived class only has contents of base class, not of its own class
// What is the output of b.f(); and why is this output produced?
// output is B, this is because b = d causes b to have contents of d (the base class) so its function f() is the one from the base class f
// What is the output of pb.f(); and why is this output produced?
// B this is because pb gets its value from b
// How can we correct this code to prevent the object slicing problem?
//