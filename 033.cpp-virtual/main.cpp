#include <iostream>
using std::cout;

int *ptr;

class A {
public:
  virtual void foo() {}
};

class B : public A {
public:
  void foo() override { bar(); }

  void bar() { *ptr = 10; }
};

int main() {
  ptr = new int;
  B b;
  A &a = b;
  a.foo();

  cout << *ptr << '\n';

  delete ptr;
}
