#ifndef MYPROJECT_UTILS_COMPLEX_H
#define MYPROJECT_UTILS_COMPLEX_H

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

complex sum(std::vector<complex> &v);

#endif
