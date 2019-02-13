#include <iostream>

int &addOne(int &i) {
  ++i;
  return i;
}

int main() {
  int j = 0;
  int a = addOne(j);
  std::cout << a << std::endl;
}
