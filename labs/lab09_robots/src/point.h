#include <cstdlib>

struct Point {
public:
  double x_;
  double y_;
  Point(double x=0, double y=0) : x_(x), y_(y) {}
  Point(const Point & pos) {
    x_ = pos.x_;
    y_ = pos.y_;
  }
};
