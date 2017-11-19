// #include <iostream>

// // exception handling
// class X {
// public:
//    X() { std::cout << "X constructed" << std::endl; }
//    X(const X& x) { std::cout << "X copy-constructed" << std::endl; }
//    ~X() { std::cout << "X destructed" << std::endl; }
// };

// void g() {
//    throw X{};
// }

// void f() {
//    try {
//       g();
//    // if not catch by reference -> catch(X x) this makes a copy of x
//    } catch (X& x) {
//       std::cout << "caught in f; rethrow" << std::endl;
//       throw;
//    }
// }

// int main() {
//    try {
//       f();
//    } catch (X& x) {
//       std::cout << "caught in main" << std::endl;
//    }
// }


// void g() {
//    throw std::string("something is wrong!");
// }

// void f() {
//    g();
//    std::cout << "never executed" << std::endl;;
// }

// int main() {
//    try {
//       f();
//    } catch (std::string &s) {
//       std::cout << s << std::endl;
//    } catch (...) { // this catches everything

//    }
//    std::cout << "execution resumes from here" << std::endl;
// }

// RAII - resource acquisition is initialisation
// encapsulate resources inside objects
// acquire resources using constructors
// destructors prevent resource leak

// theName{name} > theName = new Name{name};
// the second way may cause memory leaks

// void f() noexcept(e);
// // this means e and all functions in e also have no throwing exceptions

// Levels of safety:
// No throw - everything guaranteed to succeed
// Strong exception - operations can fail, but no side effects!
// Basic exception - no leak guarantee
// no exception


#include <iostream>

struct X {
   X() { std::cout << "X() "; }
};

struct Y {
   Y() { std::cout << "Y() "; }
};

class A{
   X x;
public:
   A() { std::cout << "A() "; }
};

class B : public A {
   Y y;
public:
   B() { std::cout << "B() "; }
};

int main() {
   B b;
}

// finalisation: reverse order of initialisation
// lifetime - period of time obj has memory allocated
// heap obj: unnamed - lifetime determined by programmer

int *p = new int[10]{}; // the {} initialises array to 0
int *q = new std::string[5]{"hi"}; // initialises first, rest empty strings
delete []p;
delete []q;
q = nullptr;
p = nullptr;

std::unique_ptr<type>