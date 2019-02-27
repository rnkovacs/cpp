#ifndef MYPROJECT_UTILS_COMPLEX_H
#define MYPROJECT_UTILS_COMPLEX_H

#include <cmath>
#include <iostream>
#include <vector>

struct complex {
  static int counter; // static class member decl (only decl!)
  
  complex() : re(0), im(0) {
    counter += 1;
    std::cout << "counter: " << counter << std::endl;
  }

  complex(double x, double y=42.) : re(x), im(y) {
    counter += 1;
    std::cout << "counter: " << counter << std::endl;
  }

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

  void print() const;
  
private:
  double re;
  double im;
};

complex sum(std::vector<complex> &v);

#endif
