void f(int *A, int n) {
  int i, j;

  for (i = n - 1; i >= 0; i--) {
    for (j = i + 1; j < n; j++)
      A[j - 1] = A[j];
    A[j - 1] = n;
  }
}

int main() {
  int n = 4;
  int A[] = {0, 1, 2, 3};
  f(A, n);
  return 0;
}
