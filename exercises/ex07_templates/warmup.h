/**
 * @file warmup.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

 // A polymorphic swap function for any type of object (an example)
template<typename T>
void MySwap( T& x, T& y) {
  T temp;
  temp = x;
  x = y;
  y = temp;
}

// A polymorphic class holding an [x,y] position of any type
template<class T>
class Position {
public:
  Position(T x=0, T y=0) : x_(x), y_(y) {}
  friend std::ostream& operator<<(std::ostream& os, const Position& p) {
    return os << "[" << p.x_ << ", " << p.y_ << "]";
  }

  // >>> ADD an overloaded operator to add two positions.

  T get_x() const { return x_; }
  void set_x(T x) { x_ = x; }
  T get_y() const { return y_; }
  void set_y(T y) { y_ = y; }

private:
  T x_;
  T y_;
};

// You still can't mix types with the above template, but ...
template<class T1, class T2>
Position<T1> operator-(Position<T1> p1, Position<T2> p2) {
  return Position<T1>(p1.get_x()-p2.get_x(), p1.get_y()-p2.get_y());
}
