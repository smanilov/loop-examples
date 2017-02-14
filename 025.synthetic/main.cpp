// This is a synthetic program with the same control flow as the function
// register-use in "levanter". This program has no meaning.
#include <iostream>

int main() {
  int x, y, z, w, u ,v;
  std::cout << "Enter 6 numbers:\n";
  std::cin >> x >> y >> z >> w >> u >> v;

  if (x) {
    return 0;
  }

  if (y) {
    return 0;
  }

  for (int i = 0; i < z; ++i) {
    if (++w) {
      return 0;
    }

    if (u--) {
      x = v;
    }

    for (int j = 0; j < v; ++j) {
      x = u;
    }

    if (--v) {
      x = z;
    }
  }

  std::cout << x << '\n';
}
