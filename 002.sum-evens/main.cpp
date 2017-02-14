// Exploring different conditions for the CDG.
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int *A = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }

  // Sum all even members of A.
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i] % 2 == 0) {
      sum += A[i];
    }
  }

  // If A contains 42, add 42 to sum once.
  for (int i = 0; i < n; ++i) {
    if (A[i] == 42) {
      sum += A[i];
      delete[] A;
      return 1;
    }
  }

  printf("%d\n", sum);
  delete[] A;
  return 0;
}
