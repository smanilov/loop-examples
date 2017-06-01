#include <cstdio>

int f() {
  int x, y[1024][1024];
  scanf("%d", &x);            // hidden store
  scanf("%d", &y[0][0]);      // hidden store
  x += y[0][0];               // store 0, load 0, load 1 (WAR load 1 - store 0)
  return x;                   // load 2                  (RAW: store 0)
}

int g() {
  int x, y[1024][1024];
  scanf("%d", &x);            // hidden store
  scanf("%d", &y[0][0]);      // hidden store
  x += y[0][0];               // store 1, load 3, load 4 (WAR load 4 - store 1)
                              //   *** interference: *** (RAW: store 0 - load 4)
                              //   *** interference: *** (WAW: store 0 - store 1)
                              //   *** interference: *** (WAR: load 2 - store 1)
  return x;                   // load 5                  (RAW: store 1)
}

int main() {
  printf("%d\n", f() + g());
  return 0;
}
