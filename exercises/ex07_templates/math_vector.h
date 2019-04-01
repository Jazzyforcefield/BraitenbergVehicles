/**
 * @file item.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef MATH_VECTOR_H_
#define MATH_VECTOR_H_

#include <cstdio>
#include <iostream>
#include <string>

class MathVector {
 public:
  explicit MathVector(double x=0, double y=0);
  bool operator<(const MathVector& v);
  friend std::ostream& operator<<(std::ostream& os, const MathVector& v);

  double get_x() const { return x_; }
  void set_x(double x) { x_ = x; }
  double get_y() const { return y_; }
  void set_y(double y) { y_ = y; }

 private:
  double x_;
  double y_;
  double length_;
};

#endif  // MATH_VECTOR_H_
