#ifndef _SHAPES_HPP_
#define _SHAPES_HPP_

class rectangle {
public:
  rectangle(int w, int h) : width(w), height(h) {}
  int area() const { return width * height; }

private:
  int width;
  int height;
};

class square {
public:
  square(int s) : side(s) {}
  int area() const { return side * side; }

private:
  int side;
};

#endif
