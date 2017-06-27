#include <iostream>
using std::cin;
using std::cout;

struct list {
  list *next;
  int val;

  list() : next(0), val(0) { }
};

void foo(list *l) {
  while (l) {
    l->val++;
    l = l->next;
  }
}

int main() {
  unsigned n;
  cin >> n;

  list *head = new list;
  list *l = head;
  for (unsigned i = 0; i < n; ++i) {
    cin >> l->val;
    l->next = new list;
    l = l->next;
  }

  foo(head);

  l = head;
  for (unsigned i = 0; i < n; ++i) {
    cout << l->val << ' ';
    l = l->next;
  }

  return 0;
}
