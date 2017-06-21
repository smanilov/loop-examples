#include <iostream>
using std::cin;

void input(int *A, unsigned n) {
  for (unsigned i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
}

// DependenceAnalysis reports a flow, where there's actually an anti dependence.
void move_one(int *A, unsigned n) {
  for (unsigned i = 0; i < n-1; ++i) {
    A[i] = A[i + 1];
  }
}

// DependenceAnalysis reports no dependence here.
void move_one_alt(int *A, unsigned n) {
  int *B = A + 1;
  for (unsigned i = 0; i < n-1; ++i) {
    A[i] = B[i];
  }
}

int main() {
  unsigned n;
  cin >> n;

  int *A = new int[n];

  input(A, n);

  move_one(A, n);

  move_one_alt(A, n);

  delete[] A;
}
