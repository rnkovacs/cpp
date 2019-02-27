class constref {
  int i;
  const int ci;
  int &ri;
public:
  constref(int data) : i(data), ci(data), ri(i) {}
};
