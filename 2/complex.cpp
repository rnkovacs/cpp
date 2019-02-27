#include <cmath>
#include <iostream>
#include <vector>

struct complex {
  complex() : re(0), im(0) {}
  complex(double x, double y=42.) : re(x), im(y) {}

  void set_re(double x) { re = x; }
  void set_im(double y) { im = y; }
  void conjugate() { im = -im; }

  void add_to_this(const complex &other) {
    re += other.re;
    im += other.im;
  }

  double abs() const {
    return sqrt(re*re + im*im);
  }

  complex add(const complex &to) const {
    return complex(re + to.re, im + to.im);
  }

  void print() const {
    std::string sign = (im < 0) ? " - " : " + ";
    std::cout << re << sign << std::abs(im) << "i" << std::endl;
  }
  
private:
  double re;
  double im;
};

complex sum(std::vector<complex> &v) {
  complex vsum(0, 0);
  for (complex &c : v)
    vsum.add_to_this(c);
  return vsum;
}

int main() {
  complex c;
  c.print();
  c.set_re(3);
  c.set_im(5);
  c.print();
  
  complex d(1, 1);
  d.print();
  
  complex e(3.14);
  e.print();
  
  std::cout << c.abs() << std::endl;
  std::cout << d.abs() << std::endl;
  
  e.print();
  e.conjugate();
  e.print();
  
  std::cout << "vector:" << std::endl;
  
  std::vector<complex> v;
  v.push_back(c);
  v.push_back(d);
  v.push_back(e);
  
  for (complex &c : v)
    c.print();
  
  std::cout << "sum:" << std::endl;
  
  complex s = sum(v);
  s.print();
  
  const complex i(0, 1);
  i.print();
  
  return 0;
}
