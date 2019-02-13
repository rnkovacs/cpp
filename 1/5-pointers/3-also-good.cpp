int main() {
  const int ci = 6;
  const int *p = &ci;

  int c = 5;
  p = &c; // const-ra mutató mutató mutathat nem-const-ra is
          // ezen a mutatón keresztül nem lehet megváltoztatni
          // más mutatón keresztül igen
}
