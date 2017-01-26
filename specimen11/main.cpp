// Figure 2 (hand drawn) of Memory Profiler document with duplicating functions.
#include <stdio.h>

void a();
void b();
void c();
void f();
void g();
void h();
void z();
void x();

void z() { c(); }

void f() {
  c();
  void (*ptr)() = g;
  ptr();
}

void g() { h(); }

void h() {
  c();
  void (*ptr)() = a;
  ptr();
  c();
}

void a() {
  b();
  c();
}

void b() {
  x();
  c();
}

void x() {
  c();
  c();
}

void c() {}

int main() {
  z();
  f();
  return 0;
}
