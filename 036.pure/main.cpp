#include <iostream>
using std::cin;

void input(int *A, unsigned n) {
  for (unsigned i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
}

void bar(int *ptr) {
  (*(ptr+1))++;
}

int baz(int *ptr) {
  return *ptr;
}

void foo(int *A, unsigned n) {
  for (unsigned i = 0; i < n-1; ++i) {
    bar(A + i);
    A[i] = A[i + 1];
  }
}

void foo2(int *A, unsigned n) {
  for (unsigned i = 0; i < n-1; ++i) {
    baz(A + i);
    A[i] = A[i + 1];
  }
}

int qux(int x) {
  return x + 1;
}

void foo3(int *A, unsigned n) {
  for (unsigned i = 0; i < n-1; ++i) {
    qux(i);
    A[i] = A[i + 1];
  }
}

int main() {
  unsigned n;
  cin >> n;

  int *A = new int[n];

  input(A, n);

  foo(A, n);

  foo2(A, n);

  foo3(A, n);

  delete[] A;
}
