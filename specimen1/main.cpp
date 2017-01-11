// A simple non-trivial program with loops.
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int *A = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += A[i];
  }

  printf("%d\n", sum);
  delete[] A;
}
