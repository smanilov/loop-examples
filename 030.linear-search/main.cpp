#include <iostream>
using std::cin;
using std::cout;

int main() {
  unsigned length = 10;
  unsigned x;
  cin >> x;

  unsigned A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  unsigned i;
  for (i = 0; i < length; ++i) {
    if (A[i] == x) {
      break;
    }
  }

  (i == length ? cout << "not found" : cout << A[i]) << '\n';
  return 0;
}
