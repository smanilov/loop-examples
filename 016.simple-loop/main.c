// The simplest of programs that has a substantial loop. Each element of an
// array is initialized to its index in the array.

int main() {
  const unsigned N = 1 << 5;
  unsigned A[N];

  for (unsigned i = 0; i < N; ++i) {
    A[i] = i;
  }
}
