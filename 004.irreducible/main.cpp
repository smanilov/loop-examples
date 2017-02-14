// Let's call this CFG the 'butterfly'.
// It looks like this:
//
//     A
// ,. / \,-,
// | B1 B2 |
// |  \ /  |
// |   C   |
// |  / \  |
// | D1 D2 |
// `-`\ /`-`
//     E
//
// Where the edges between B1-D1 and B2-D2 are actually 'back-edges' which is to
// say the direction is from D1 to B1 and from D2 to B2 (illustrated by edges
// always leaving from the bottom of a node and entering through the top).
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
A:
  if (A[i] % 2 == 0) {
  B1:
    sum += A[i];
  } else {
  B2:
    sum -= A[i];
  }
C:
  if (A[i] % 2 == 0) {
  D1:
    sum += A[i];
    if (++i < n) {
      goto B1;
    }
  } else {
  D2:
    sum -= A[i];
    if (++i < n) {
      goto B2;
    }
  }
E:

  printf("%d\n", sum);
  delete[] A;
}
