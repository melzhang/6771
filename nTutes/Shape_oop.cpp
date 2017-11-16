#include <iostream>

// base class
class Shape {
public:
  Shape(unsigned int width=0, unsigned int height=0):
    width_{width}, height_{height} {}

  void setWidth(unsigned int width) {
    width_ = width;
  }
  void setHeight(unsigned int height) {
    height_ = height;
  }

  unsigned int getArea() {
    std::cout << "Shape Area: " << '\n';
    return (width_ * height_);
  }

protected:
  unsigned int width_;
  unsigned int height_;
};

// subclass
class Rectangle: public Shape {
public:
  Rectangle(unsigned int width=0, unsigned int height=0):
    Shape(width, height) {}

  unsigned int getArea() {
    std::cout << "Rectangle Area: " << '\n';
    return (width_ * height_);
  }
};

int main() {
  Shape s1{3,2};

  Rectangle r;
  r.setWidth(5);
  r.setHeight(4);

  Rectangle r2{3,4};

  std::cout << s1.getArea() << '\n';
  std::cout << r.getArea() << '\n';
  std::cout << r2.getArea() << '\n';


  return 0;
}
