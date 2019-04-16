/**
 * @file object.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#include <cstdio>
#include <iostream>
#include <cstring>

#include "circle.h"

Circle::Circle(double r) : radius_(r), color_(kBlue) {}

// >>>> WRITE THIS overloaded operator using radius
bool Circle::operator<(const Circle& rhs) {
  return true;
}

std::ostream& operator<<(std::ostream& os, const Circle& c) {
  return os << "radius = " << c.radius_;
}
