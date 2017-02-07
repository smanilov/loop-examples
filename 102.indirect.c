// A function takes a pointer to the start of an array and the length of the
// array and increments each element with its index in the array. The single
// level of indirection should be enough to defeat compiler optimizations based
// on the array not being used.
void foo(int *A, int len) {
  int i = 0;

  for(i = 0; i < len; i++)
    A[i] = A[i] + i;

  return;
}

const int N = 1 << 21;
int A[N];

int main() {

  foo(A, N);

  return 0;
}
