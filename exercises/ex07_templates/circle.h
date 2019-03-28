/**
 * @file circle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <cstdio>
#include <iostream>
#include <string>

enum Color {kRed, kBlue, kGreen, kOrange};

class Circle {
public:
  explicit Circle(double r=1);
  bool operator<(const Circle& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Circle& c);

  int get_radius() const { return radius_; }
  void set_radius(double r) { radius_ = r; }

private:
  double radius_;
  Color color_;
};

#endif  // CIRCLE_H_
