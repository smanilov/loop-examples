#include <iostream>
using std::cout;

#include <cstdlib>

int *x;

void f() {
}

void g() {
  cout << *x;
}

int main() {
  x = new int;
  f();
  for (int i = 0; i < 10; ++i) {
    *x = i;
    if (i == 5) { f(); f(); break; } //exit(0);
    g();
  }

  for (int i = 0; i < 10; ++i) {
    *x = i;
    if (i == 5) { f(); f(); break; } //exit(0);
    g();
  }

  delete x;
}
