// The simplest of programs that has a substantial loop. Each element of an
// array is initialized to its index in the array.

const unsigned N = 1 << 30;
unsigned A[N];

int main() {

  for (unsigned i = 0; i < N; ++i) {
    A[i] = i;
  }
}
