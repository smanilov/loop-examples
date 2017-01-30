// Figure 2 (hand drawn) of Memory Profiler document with duplicating functions.
#include <stdio.h>

void a();
void b();
void c();
void f();
void g();
void h();
void x();

int main() {
  g();  // Offset 1
  f();  // Offset 3
  return 0;
}

void f() {
  c();  // Offset 1
  c();  // Offset 2
  c();  // Offset 3
  c();  // Offset 4
  c();  // Offset 5
  c();  // Offset 6
  void (*ptr)() = g;
  ptr();  // Offset 7
}

void g() {
  h();  // Offset 1
}

void h() {
  c();  // Offset 1
  void (*ptr)() = a;
  ptr();  // Offset 2
  c();  // Offset 3
}

void a() {
  b();  // Offset 1
  c();  // Offset 6
}

void b() {
  x();  // Offset 1
  c();  // Offset 4
}

void x() {
  c();  // Offset 1
  c();  // Offset 1
}

void c() {}
