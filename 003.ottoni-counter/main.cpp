// A loop with two reverse edges in its CFG.
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int *A = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }

  {
  int sum = 0;
  int i = 0;
L0:
  if (A[i] % 2 == 0) {
    sum += A[i++];
    goto L0;
  }
  if (A[i++] < n) goto L0;

  printf("%d\n", sum);
  }

// Unrolled version:
  {
    int sum = 0;
    int i = 0;
Lx_:
    if (A[i] % 2 == 0) {
      sum += A[i++];
      goto L0_;
    }
    if (A[i++] < n) goto L0_;
    else goto end;
L0_:
    if (A[i] % 2 == 0) {
      sum += A[i++];
      goto L0_;
    }
    if (A[i++] < n) goto L0_;
    else goto end;
end:

    printf("%d\n", sum);
  }
  delete[] A;
}
