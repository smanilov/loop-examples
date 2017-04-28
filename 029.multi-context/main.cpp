#include <iostream>
using std::cout;

int f(int *ptr, unsigned length) {
  int sum = 0;
  for (unsigned i = 0; i < length; ++i) {
    if (ptr[i] % 2 == 1) {
      ptr[i] += ptr[i / 2];
    }
    sum += ptr[i];
  }
  return sum;
}

int main() {
  unsigned length = 10;
  int sum = 0;

  int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  sum += f(A, length);

  int B[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
  sum += f(B, length);

  cout << sum << '\n';
}
