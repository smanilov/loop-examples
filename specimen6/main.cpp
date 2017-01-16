// Attempting to replicate the CFG from Figure 11.25 of Aho and Ullman 1972.
#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  int *A = new int[n];

  int i = -1;
  int sum = 0;
_2:
  ++i;
_3:
  if (A[i] % 2 == 0) {
    goto _4;
  }
_7:
  sum += A[i];
  goto _2;
_4:
  if (i < n && A[i] % 3 == 0) {
    ++i;
    goto _4;
  }
_5:
  if (i < n && A[i] % 5 != 0) {
    goto _2;
  }
_6:
  sum += A[i++];
  if (i < n) {
    goto _3;
  }
  std::cout << sum << '\n';

  delete[] A;
}
