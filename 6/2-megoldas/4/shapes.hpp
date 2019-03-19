#ifndef _SHAPES_HPP_
#define _SHAPES_HPP_

#include <algorithm>
#include <vector>

struct shape {
  virtual ~shape() {}
  virtual int area() const = 0;
  virtual shape *clone() const = 0;
};

class rectangle : public shape {
public:
  rectangle(int w, int h) : width(w), height(h) {}
  int area() const { return width * height; }
  rectangle *clone() const { return new rectangle(*this); }

private:
  int width;
  int height;
};

class square : public shape {
public:
  square(int s) : side(s) {}
  int area() const { return side * side; }
  square *clone() const { return new square(*this); }

private:
  int side;
};

struct area_adder {
  int operator()(int sum, shape *s) {
    return sum + s->area();
  }
};

int area_add(int sum, shape *s) {
  return sum + s->area();
}

class shape_group {
public:
  ~shape_group() {
    for (shape *s : shapes)
      delete s;
  }

  void add(const shape &s) {
    shapes.push_back(s.clone());
  }

  int area() const {
    return std::accumulate(shapes.begin(), shapes.end(), 0, area_add);
//  return std::accumulate(shapes.begin(), shapes.end(), 0, area_adder());
  }

private:
  std::vector<shape *> shapes;
};

#endif
