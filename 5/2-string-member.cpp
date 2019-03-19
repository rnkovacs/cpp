#include <iostream>

class safe_string {
public:
  safe_string(const char *c) : s(c ? c : "") {}
  friend std::ostream &operator<<(std::ostream &os, const safe_string &ss);

private:
  std::string s;
};

std::ostream &operator<<(std::ostream &os, const safe_string &ss) {
  os << ss.s;
  return os;
}

int main() {
  // std::string s(nullptr);
  // std::string s = nullptr;

  safe_string ss(nullptr);
  std::cout << ss << std::endl;

  safe_string sss = "hello";
  std::cout << sss << std::endl;
}
