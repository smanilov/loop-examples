//
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int *A = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }

  int sum = 0;
  int i = 0;
L0:
  if (A[i] % 2 == 0) {
  left0:
    sum += A[i];
  } else {
  right0:
    sum -= A[i];
  }
  printf("%d", sum);
  if (A[i] % 2 == 0) {
    sum += A[i];
    if (++i < n) {
      goto left0;
    }
  } else {
    sum -= A[i];
    if (++i < n) {
      goto right0;
    }
  }

  printf("%d\n", sum);
  delete[] A;
}
