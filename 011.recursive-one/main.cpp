// Treat all functions in a recursive SCC as one and assign unique offsets to
// all calls in the SCC.
#include <stdio.h>

bool is_even(int x);
bool is_odd(int x);
int dec(int x);

bool is_even(int x) {
  if (x == 0) return true;
  return is_odd(dec(x));
}

bool is_odd(int x) {
  if (x == 0) return false;
  return is_even(dec(x));
}

int dec(int x) { return x - 1; }

int main() {
  int n;
  scanf("%d", &n);

  printf("%d is %s\n", n, !is_even(n) ? "odd" : "even");
  return 0;
}
