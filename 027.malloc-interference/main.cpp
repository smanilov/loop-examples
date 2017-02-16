#include <cstdlib>
#include <cstdio>

int main() {
  unsigned n;
  scanf("%u", &n);
  int *x = (int *)malloc(sizeof *x * n);
  printf("%p\n", x);
  for (unsigned i = 0; i < n; ++i) {
    unsigned t;
    scanf("%u", &t);
    x[i] = t;
  }

  int sum = 0;
  for (unsigned i = 0; i < n; ++i) {
    sum += x[i];
  }

  delete[] x;

  printf("%d\n", sum);

  int *y = (int *)malloc(sizeof *y * n);
  printf("%p\n", y);
  for (unsigned i = 0; i < n; ++i) {
    unsigned t;
    scanf("%u", &t);
    y[i] = t;
  }

  sum = 0;
  for (unsigned i = 0; i < n; ++i) {
    sum += y[i];
  }

  delete[] y;

  printf("%d\n", sum);
  return 0;
}
