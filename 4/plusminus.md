## +/-

2019. márc. 6.

**1. Az alábbi kód két okból sem fordul le. Mi a két ok? Javitsd!** (0.8 pont)

```c++
class A {
  int i;
  const double d;
public:
  A(int ii, double dd) {
    i = ii;
    d = dd;
  }
}
```

Hint: az egyik szintaktikai.

**2. Az alábbi programban nemdefiniált viselkedés van. Mi okozza? Javitsd ki!
     Mit ir ki javitás előtt és után?** (0.7 pont)

```c++
#include <iostream>

class A {
  const double d;
  int i;
public:
  A(int data): i(data), d(i) {
    std::cout << i << ' ' << d << std::endl;
  }
};

int main() {
  A a(2);
}
```

**3. Mi a hiba az alábbi kódban? Javitsd!** (0.5 pont)

```c++
struct complex {
  static int counter = 42;
};
```
