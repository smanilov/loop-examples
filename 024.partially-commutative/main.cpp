// A partially commutative loop.
typedef unsigned char uchar;
const uchar RC_ERROR = 255;

struct maybe_int {
  bool valid;
  int value;
};

// Parse a char array that represents an int in base 10.
maybe_int parse_int(char *str) {
  maybe_int res = { true, 0 };
  bool neg = str[0] == '-';
  str += neg;
  while (*str != 0) {
    int d = *str++ - '0';
    res.valid &= d >= 0 && d < 10;
    if (!res.valid) break;
    res.value = res.value * 10 + d;
  }
  res.value *= 1 - 2 * neg;
  return res;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    return RC_ERROR;
  }

  unsigned n;
  {
    maybe_int maybe_max = parse_int(argv[1]);
    if (!maybe_max.valid || maybe_max.value < 0) {
      return RC_ERROR;
    }
    n = maybe_max.value;
  }

  const unsigned N = 4;
  int A[N] = { 0 };

  for (unsigned i = 0; i < n; ++i) {
    if (i < 50) {
      ++A[i % N];
    } else {
      A[i % N] = A[(i+1) % N] + 1;
    }
  }

  // The current element is always either the same as the next one or one less.
  return !((A[n % N] == A[(n+1) % N]) || (A[n % N] == A[(n+1) % N] - 1));
}
