#include <iostream>

int &addOne(int &i) {
  int ret = ++i;
  return ret;
}

int main() {
  int j = 0;
  int a = addOne(j);
  std::cout << a << std::endl;
}
