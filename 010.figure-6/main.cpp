// Figure 6 of Memory Profiler document (10 Feb 2017).
#include <stdio.h>

void a();
void b();
void c();
void d();
void e();
void f();
void g();
void h();
void i();
void j();
void k();
void l();
void m();

void a() { c(); }

void b() {
  d();
  e();
  void (*ptr)() = f;
  ptr();
}

void c() {}

void d() {}

void e() {}

void f() { g(); }

void g() {
  e();
  void (*ptr)() = h;
  ptr();
  k();
}

void h() {
  i();
  k();
}

void i() {
  j();
  k();
}

void j() {
  l();
  m();
}

void k() {}

void l() {}

void m() {}

int main() {
  a();
  b();
  return 0;
}
