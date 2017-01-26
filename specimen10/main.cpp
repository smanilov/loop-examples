// Subpart of Figure 2 (hand drawn) of Memory Profiler document.
#include <stdio.h>

void a();
void b();
void c();
void d();
void e();
void f();
void g();
void h();
void z();
void y();
void x();
void w();
void v();
void u();
void t();

void z() { y(); }

void y() {}

void f() {
  v();
  void (*ptr)() = g;
  ptr();
}

void g() { h(); }

void h() {
  y();
  void (*ptr)() = a;
  ptr();
  e();
}

void a() {
  b();
  c();
}

void b() {
  x();
  d();
}

void x() {
  t();
  u();
}

void t() {}

void u() {}

void c() {}

void d() {}

void e() {}

void v() {}

int main() {
  z();
  f();
  return 0;
}
