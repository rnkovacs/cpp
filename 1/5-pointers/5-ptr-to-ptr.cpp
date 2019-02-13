int main() {
  int c, d;

  int *p = &c;
  int **q = &p;
  *q = &d; // megváltoztatjuk, p hova mutasson
}
