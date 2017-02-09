// Example having an unconditional finish of a loop that is also a start of
// another loop.
//
// (This is impossible: if the jump is unconditional to a block after the loop,
// then it cannot also loop back; if it is unconditional to the entry, then it
// cannot also be a finish!)

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
  if (i == 9) {
    // This block is already outside the loop!
    A[i] += 10;
    goto cond2;
  }
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
