int main() {
  unsigned x;

  const unsigned N = 1 << 5;
  unsigned A[N];

  for (unsigned i = 0; i < N; ++i) {
    A[i] = i;
    x = A[i];
  }

  return (x + 1) % N;
}
