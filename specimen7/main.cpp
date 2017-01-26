// Subset of recursive example from KK17.
#include <stdio.h>

bool is_odd(unsigned n);

bool is_even(unsigned n) {
  if (n == 0) return true;
  else return is_odd(n - 1);
}

bool is_odd(unsigned n) {
  if (n == 0) return false;
  else return is_even(n - 1);
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d is %s\n", n, is_even(n) ? "even" : "odd");
  return 0;
}
