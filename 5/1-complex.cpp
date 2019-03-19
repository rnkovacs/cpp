#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

struct complex {
  complex() : re(0), im(0) {}
  complex(double x) : re(x), im(0) {}
  complex(double x, double y) : re(x), im(y) {}

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
    std::cout << re << sign << std::abs(im) << 'i' << std::endl;
  }

  //complex operator+(const complex &other) const {
  //  return complex(re + other.re, im + other.im);
  //}

  friend complex operator+(const complex &lhs, const complex &rhs);
  friend std::ostream &operator<<(std::ostream &os, const complex &num);

private:
  double re;
  double im;
};

complex operator+(const complex &lhs, const complex &rhs) {
  return complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

std::ostream &operator<<(std::ostream &os, const complex &num) {
  std::string sign = (num.im < 0) ? " - " : " + ";
  os << num.re << sign << std::abs(num.im) << 'i';
  return os;
}

complex sum(const std::vector<complex> &v) {
  complex vsum(0, 0);
  for (const complex &c : v)
    vsum.add_to_this(c);
  return vsum;
}

int main() {
  const complex i(0, 1);
  i.print();

  std::cout << i << std::endl;
  std::cout << complex(3) << std::endl;

  std::cout << i + complex(3) << std::endl;
  std::cout << i + 3 << std::endl;
  std::cout << 3 + i << std::endl;

  std::list<complex> l;
  l.push_back(i);
  l.push_back(complex(3));
  l.push_front(complex(4.1, 6.4));
  l.push_back(complex(1));

  for (std::list<complex>::iterator it = l.begin(), end = l.end(); it != end; ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;

  for (auto it = l.begin(), end = l.end(); it != end; ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;

  for (const complex &c : l)
    std::cout << c << ' ';
  std::cout << std::endl;

  return 0;
}
