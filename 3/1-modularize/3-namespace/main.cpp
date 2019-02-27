#include <cmath>
#include <iostream>
#include <vector>

#include "complex.h"
#include "complex.h"

int main() {
  cx::complex c;
  c.print();
  c.set_re(3);
  c.set_im(5);
  c.print();
  
  cx::complex d(1, 1);
  d.print();
  
  cx::complex e(3.14);
  e.print();
  
  std::cout << c.abs() << std::endl;
  std::cout << d.abs() << std::endl;
  
  e.print();
  e.conjugate();
  e.print();
  
  std::cout << "vector:" << std::endl;
  
  std::vector<cx::complex> v;
  v.push_back(c);
  v.push_back(d);
  v.push_back(e);
  
  for (cx::complex &c : v)
    c.print();
  
  std::cout << "sum:" << std::endl;
  
  cx::complex s = sum(v);
  s.print();
  
  const cx::complex i(0, 1);
  i.print();
  
  return 0;
}
