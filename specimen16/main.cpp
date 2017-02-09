// Example having a finish of a loop that is also a restart of another loop.
//
////////////////////////////////////////////////////////////////////////////////
///                                                                           //
///  WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING  //
///                                                                           //
///  DON'T COMPILE THIS FILE; IT'S FOR ILLUSTRATION PURPOSES ONLY. THE CODE   //
///  IN main.ll IS MANUALLY EDITED TO PRODUCE REQUIRED CFG.                   //
///                                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
  unsigned n, m;
  unsigned i = 0, j = 0;

  std::cin >> n;
  int *B = new int[n];

  --i;
loop1:
  ++i;
  if (i >= n) goto end_loop1;
  B[i] = 0;
  std::cin >> m;
  j = 0;
loop2:
  if (j >= m) goto loop1;
  int x;
  std::cin >> x;
  B[i] += x;
  ++j;
  goto loop2;
end_loop1:

  int sum = 0;
  for (i = 0; i < n; ++i) {
    sum += B[i];
  }

  std::cout << sum << '\n';

  delete[] B;

  return 0;
}
