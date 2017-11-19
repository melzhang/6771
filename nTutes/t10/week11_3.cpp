// draw vtables for these


/*
A:
[0| &A:f(int)]
[1| &A:g()]
[3| &A:~A()]
*/
class A {
public:
  virtual void f(int) {}
  virtual int g() {}
  void a() {}
  virtual ~A() {}
};

/*
B:
[0| &B:f(int)]
[1| &A:g()]
[3| &A:~A()]
[4| &B:h()]
*/
class B : public A {
public:
  virtual void f(int) {}
  virtual int h() {}
};

/*
C:
[0| &C:f(int, int)]
[1| &A:g()]
[3| &A:~A()]
[4| &B:h()]
[4| &C:x()]
*/
class C : public B {
public:
  virtual void f(int, int) {}
  virtual void x() {}
  static void b() {}
};

int main() {
  return 0;
}
