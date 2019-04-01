/**
 * @file math_vector.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

#include "math_vector.h"

MathVector::MathVector(double x, double y) : x_(x), y_(y) {
  length_ = pow(x_*x_ + y_*y_, 0.5);
}

// >>>> WRITE THIS overloaded operator using length
bool MathVector::operator<(const MathVector& v) {
  return true;
}

std::ostream& operator<<(std::ostream& os, const MathVector& v) {
  return os << "|" << v.x_ << "," << v.y_ << "| = " << v.length_;
}
