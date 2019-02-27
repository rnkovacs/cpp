#include <cmath>
#include <iostream>
#include <vector>

#include "complex.h" // headers
#include "complex.h"

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
