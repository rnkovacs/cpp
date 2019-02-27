#include <iostream>

struct book {
  book(const char *title) : title(title), price(1000) {}
  book(const char *title, int price) : title(title), price(price) {}
  void cheaper_than(const book &b) {
    if (b.price < price)
      std::cout << b.title << " is cheaper than " << title << std::endl;
  }
private:
  const char *title;
  int price;
};

int main() {
  book a("Harry Potter", 5000);
  a.cheaper_than("Tom Sawyer");
  return 0;
}
