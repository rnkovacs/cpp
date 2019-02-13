#include <iostream>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int c = 0, d = 10;
  swap(&c, &d);
  std::cout << c << " " << d << std::endl;
}
