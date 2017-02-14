// Figure 5 of Memory Profiler document (10 Feb 2017).
#include <stdio.h>

void F() {
}

void D() {
  F();
}

void E() {
  F();
}

void B() {
  D();
  E();
}

void C() {
  D();
  E();
}

// A
int main() {
  B();
  C();
  return 0;
}
