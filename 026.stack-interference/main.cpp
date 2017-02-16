#include <cstdio>

int f() {
  int x, y[1024][1024];
  scanf("%d", &x);
  scanf("%d", &y[0][0]);
  x += y[0][0];
  return x;
}

int g() {
  int x, y[1024][1024];
  scanf("%d", &x);
  scanf("%d", &y[0][0]);
  x += y[0][0];
  return x;
}

int main() {
  printf("%d\n", f() + g());
  return 0;
}
