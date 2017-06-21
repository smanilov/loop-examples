#include <iostream>

void input(int *A, unsigned n) {
  for (unsigned i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
}

void move(int *A, int *B, unsigned n) {
  for (unsigned i = 0; i < n; ++i) {
    B[i] = A[i];
  }
}

void increment(int *A, unsigned n) {
  for (unsigned i = 0; i < n; ++i) {
    ++A[i];
  }
}

void move_one(int *A, unsigned n) {
  for (unsigned i = 1; i < n; ++i) {
    A[i - 1] = A[i];
  }
}

void move_third(int *A, unsigned n) {
  // There shouldn't be a dependence here, because there is no overlap.
  for (unsigned i = 0; i < n/3; ++i) {
    A[i+2*n/3] = A[i];
  }
}

void move_half(int *A, unsigned n) {
  // There shouldn't be a dependence here, because there is no overlap.
  for (unsigned i = 0; i < n/2; ++i) {
    A[i+n/2] = A[i];
  }
}

void move_two_thirds(int *A, unsigned n) {
  // There should be a dependence here, because there is overlap.
  for (unsigned i = 0; i < 2*n/3; ++i) {
    A[i+n/3] = A[i];
  }
}

void move_two_thirds2(int *A, unsigned n) {
  // There should be a dependence here, because there is overlap.
  // This is equivalent to move_two_thirds.
  int *B = A + n/3;
  for (unsigned i = 0; i < 2*n/3; ++i) {
    B[i] = A[i];
  }
}

// A pure function.
int half(int x) {
  return x / 2;
}

int main() {
  unsigned n;
  std::cin >> n;
  int *A = new int[3 * n / 2];

  input(A, n);

  increment(A, n);

  move(A, A + half(n), n);

  move_one(A, n);

  move_third(A, n);

  move_half(A, n);

  move_two_thirds(A, n);

  move_two_thirds2(A, n);

  delete[] A;

  return 0;
}
