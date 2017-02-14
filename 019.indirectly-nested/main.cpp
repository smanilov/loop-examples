typedef unsigned char uchar;
const uchar RC_ERROR = 255;

struct maybe_ll {
  bool valid;
  int value;
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

const unsigned N = 4;
int A[N] = {0};

void f(unsigned n, unsigned j) {
  for (unsigned i = 0; i < n; ++i) {
    ++A[(j * n + i) % N];
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    return RC_ERROR;
  }

  unsigned n;
  {
    maybe_ll maybe_max = parse_int(argv[1]);
    if (!maybe_max.valid || maybe_max.value < 0) {
      return RC_ERROR;
    }
    n = maybe_max.value;
  }

  for (unsigned i = 0; i < n; ++i) {
    f(n, i);
  }

  return !((A[n % N] != A[(n + 1) % N]) || (n % N == 0));
}
