#include <iostream>
using std::cout;

class A {
public:
  int x;

  A() {
    x = 10;
  }
  ~A() {
    x = 0;
  }
};

void foo(A *as) {
  cout << as[3].x << '\n';
}

int main() {
  A* as = new A[10];
  foo(as);
  delete [] as;
}
