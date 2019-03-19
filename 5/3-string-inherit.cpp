#nclude <iostream>

struct safe_string : public std::string {
  safe_string(const char *c) : std::string(c ? c : "") {}
};

int main () {
  safe_string s(nullptr);
  std::cout << s << std::endl;
}
