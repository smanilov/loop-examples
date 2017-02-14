// To avoid including standard libraries parsing a string to an int is
// implemented manually. The first CLI argument is taken as the iteration count
// of a loop that goes over a cyclic array of a fixed size and increments its
// elements consequently. A sanity check is returned (should be 0) in case of
// success, or an error code if parsing failed or there wasn't exactly one
// argument on the CLI.
typedef unsigned char uchar;
const uchar RC_ERROR = 255;

struct maybe_ll {
  bool valid;
  long long value;
};

// Parse a char array that represents an int in base 10.
maybe_ll parse_int(char *str) {
  maybe_ll res = {true, 0};
  bool neg = str[0] == '-';
  str += neg;
  while (*str != 0) {
    int d = *str++ - '0';
    res.valid &= d >= 0 && d < 10;
    if (!res.valid)
      break;
    res.value = res.value * 10 + d;
  }
  res.value *= 1 - 2 * neg;
  return res;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    return RC_ERROR;
  }

  unsigned long long n;
  {
    maybe_ll maybe_max = parse_int(argv[1]);
    if (!maybe_max.valid || maybe_max.value < 0) {
      return RC_ERROR;
    }
    n = maybe_max.value;
  }

  const unsigned N = 4;
  int A[N] = {0};

  for (unsigned long long i = 0; i < n; ++i) {
    ++A[i % N];
  }

  // If the current element is same as the next one, then the current element is
  // the last one in the array: A[n % N] == A[(n+1) % N] => (n+1) % N == 0.
  // Equiv to: A[n % N] != A[(n+1) % N] || (n+1) % N == 0.
  // Return the opposite to have a rv of 0 on success.
  return !((A[n % N] != A[(n + 1) % N]) || (n % N == 0));
}
