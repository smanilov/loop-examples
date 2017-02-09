// Example having a finish of a loop that is also a start of another loop.
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

  std::cin >> n >> m;
  int *A = new int[n];
  int sum = 0;

cond1:
  if (i >= n) goto cond2;
  std::cin >> A[i];
  ++i;
  goto cond1;
cond2:
  if (j >= m) goto end;
  sum += A[j];
  ++j;
  goto cond2;
end:

  std::cout << sum << '\n';

  return 0;
}
