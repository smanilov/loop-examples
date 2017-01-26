// Figure 2 (hand drawn) of Memory Profiler document.
#include <stdio.h>

void h() {
}

void f() {
  h();
}

void g() {
  h();
}

void a() {
  f();
  g();
}

void b() {
  f();
  g();
}

int main() {
  a();
  b();
  return 0;
}
