// #include<iostream>
// using namespace std;
// int main() {
//    int a[] = { 1, 2 };
//    int *r = a;
//    int **p = &r;
//    int *&q = *p;
//    q = q + 1;
//    cout << **p << " " << *q << endl;
// }

// #include<list>
// #include<iostream>
// using namespace std;
     
// class X {
// public:
//    X() { cout << "ctor "; }
//    X(const X&) { cout << "copy-ctor "; }
//    ~X() { cout << "dtor "; }
// };

// int main() {
//   list<X**> l;
//   X *x1 = new X();
//   X** x2 = &x1;
//   l.push_back(x2);
// }

// #include<list>
// #include<iostream>
// using namespace std;

// class B {
// public:
//    virtual void f() { cout << "B::f() "; }
//    void g() { cout << "B::g() "; };
// };

// class D : public B {
// public:
//    virtual void f() { cout << "D::f() "; }
//    void g() { cout << "D::g() "; };
// };

// int main() {
//     B *o1 = new D();
//     o1->f();
//     o1->g();
//     B o2 = *o1;
//     o2.f();
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Y {
// public:
//    string* operator->() { return new string("abc"); }
// };
// class X {
// public:
//    Y* operator->() { return new Y(); }
// };

// int main() {
//    X x;
//    cout << x->size() << endl;
// }

#include <iostream>
using namespace std;
class A1 {
public:
~A1() { cout << "~A1 "; } };
class A2 {
public:
  ~A2() {
    cout << "~A2 ";
} private:
A1 a1; };
  class A3 {
public:
    ~A3() {
      cout << "~A3 ";
}
private:
A1 a1;
A2 a2;
};

int main() {
    A3 a3;
}
