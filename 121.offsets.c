// The simplest of programs that has a substantial loop. Each element of an
// array is initialized to its index in the array.

int main(int argc, char *argv[]) {
  const unsigned N = 1 << 5;
  unsigned B[N];
  unsigned A[N];
  B[0] = argc;
  B[1] = (unsigned)argv;

  for (unsigned i = 0; i < N; ++i) {
    A[i] = i;
    B[i] = i;
  }

  return ((unsigned)&B[N - 1]) % 4;
}
