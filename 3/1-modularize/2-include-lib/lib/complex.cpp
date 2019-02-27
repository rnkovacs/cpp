#include <cmath>
#include <iostream>
#include <vector>

#include "complex.h"

complex sum(std::vector<complex> &v) {
  complex vsum(0, 0);
  for (complex &c : v)
    vsum.add_to_this(c);
  return vsum;
}
