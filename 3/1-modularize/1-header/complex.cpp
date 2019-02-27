#include <cmath>
#include <iostream>
#include <vector>

#include "complex.h"

complex sum(std::vector<complex> &v) { // user function definition
  complex vsum(0, 0);
  for (complex &c : v)
    vsum.add_to_this(c);
  return vsum;
}

void complex::print() const { // member function definition
  std::string sign = (im < 0) ? " - " : " + ";
  std::cout << re << sign << std::abs(im) << "i" << std::endl;
}
