#include <iostream>
using std::cin;
using std::cout;

int *A;
int sum;

void f(int i) {
  A[i] = i * 3;
}

void g(int i) {
  sum += A[i];
}

int main() {
  unsigned n;
  cin >> n;

  A = new int[n];
  sum = 0;

  for (unsigned i = 0; i < n; ++i) {
    f(i);
    g(i);
  }

  cout << sum << '\n';
  return 0;
}
