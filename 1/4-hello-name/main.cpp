#include <iostream>
#include <string>

int main() {
  std::cout << "Enter your name: ";
  //std::string name;
  //std::string name = "zip";
  std::string name("zup");
  std::cin >> name;
  std::cout << "Hello " << name << "!" << std::endl;
  return 0;
}
