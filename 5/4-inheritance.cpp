#include <iostream>
#include <vector>

struct animal {
  animal() { std::cout << "constructing animal\n"; }
  virtual ~animal() { std::cout << "destructing animal\n"; }
  virtual void noise() const { std::cout << "general animal noise\n"; }
};

struct dog : public animal {
  dog() { std::cout << "constructing dog\n"; }
  ~dog() override { std::cout << "destructing dog\n"; }
  void noise() const override { std::cout << "bark\n"; }
};

struct cat : public animal {
  cat() { std::cout << "constructing cat\n"; }
  ~cat() override { std::cout << "destructing cat\n"; }
  void noise() const override { std::cout << "meow\n"; }
};

int main() {
  // animal a;

  // animal *a = new animal();
  // delete a;

  // dog *dd = new dog();
  // delete dd;

  // cat *cc = new cat();
  // delete cc;

  dog *d = new dog();
  cat *c = new cat();

  std::vector<animal *> v;
  v.push_back(d);
  v.push_back(c);

  for (animal *a : v)
    delete a;
    //a->noise();

  //delete c;
  //delete d;

  return 0;
}
