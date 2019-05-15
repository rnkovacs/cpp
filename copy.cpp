#include <iostream>

/* 1. Mit értünk egy osztály shallow és deep copyja közt?
 *    Mikor lényeges a különbség?
 *    Milyen speciális tagfüggvényeket kell megirnunk ilyen esetben,
 *    és miért nem jók a forditó által generáltak?
 *
 * 2. Irj 3 speciális tagföggvényt az alábbi osztályba úgy, hogy minden
 *    NumOnHeap objektum független, különálló tárhelyet kapjon!
 */

struct NumOnHeap {
  NumOnHeap(int par) : num(new int(par)) {}
  void changeTo(int par) { *num = par; }
  friend std::ostream &operator<<(std::ostream &, const NumOnHeap &);

private:
  int *num;
};

std::ostream &operator<<(std::ostream &os, const NumOnHeap &n) {
  os << *(n.num) << '\t';
  return os;
}

int main() {
  NumOnHeap a(42);
  NumOnHeap b(-137);
  NumOnHeap c(999);

  NumOnHeap d = a;
  b = c;

  std::cout << "a\tb\tc\td" << std::endl;
  std::cout << a << b << c << d << std::endl;

  b.changeTo(-1);
  d.changeTo(-2);

  std::cout << "\nchanged b to -1, d to -2\n" << std::endl;
  std::cout << "a\tb\tc\td" << std::endl;
  std::cout << a << b << c << d << std::endl;
}
