int main(int argc, char *_[]) {
  const unsigned N = 1 << 5;
  unsigned A[N];

  for (unsigned i = 0; i < N; ++i) {
    A[i] = i;
  }

  return argc + A[0];
}
