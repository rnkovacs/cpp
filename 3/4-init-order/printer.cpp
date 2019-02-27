#include <iostream>

class printer {
  int x, y;
public:
  printer(int i) : y(i), x(y) {
    std::cout << x << ' ' << y << std::endl;
  }
};

int main() {
  printer(3);
}
