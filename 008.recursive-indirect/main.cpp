// Full recursive and indirect call example from KK17.
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

int inc(int n) {
  return n + 1;
}

int dec(int n) {
  return n - 1;
}

int main() {
  int n;
  scanf("%d", &n);

  int (*fptr)(int);
  if (is_even(n)) {
    fptr = &inc;
  } else {
    fptr = &dec;
  }

  printf("%d is %s\n", fptr(n), is_even(n) ? "odd" : "even");
  return 0;
}
