#include <cassert>

#include "array_heap.hpp"

int main() {
  ArrayOnHeap a(32, 2);
  assert(a.size() == 2);
  assert(a.get()[0] == 32);
  assert(a.get()[1] == 32);

  ArrayOnHeap b(745, 2);
  ArrayOnHeap c(-13, 6);
  ArrayOnHeap d = c;
  b = a;

  assert(d.get() != c.get());
  assert(b.get() != a.get());
}
