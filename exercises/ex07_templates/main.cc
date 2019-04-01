/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

#include "warmup.h"

#include "math_vector.h"
#include "circle.h"
#include "data.h"

int main() {
  // Example of using MySwap defined in warmup.h
  int x = 10;
  int y = 20;
  std::string first("first");
  std::string second("second");
  std::cout << "x y : " << x << " " << y << std::endl;
  MySwap( x, y);
  std::cout << "x y : " << x << " " << y << std::endl;
  std::cout << "first second : " << first << " " << second << std::endl;
  MySwap( first, second);
  std::cout << "first second : " << first << " " << second << std::endl;

  // >>> Define 2 position instances with a double.
  // >>> Print out the addition of the 2 (operator<< has been defined).

  // >>> Define 2 position instances with an int.
  // >>> Print out the addition of the 2.

  // Use MySwap to swap the values of the two positions and print it out.

  // Use your defined positions to try operator- with double-int
  // Use your defined positions to try operator- with int-double

  // Using class Data that stores and sorts integers ...
  Data integers;
  integers.AddDatum(6);
  integers.AddDatum(100);
  integers.AddDatum(-3);
  integers.AddDatum(25);
  std::cout << integers << std::endl;
  integers.SelectionSort();
  std::cout << integers << std::endl;

  /*
  // >> Define an instance of Data of type Circle

  circles.AddDatum(Circle(2));
  circles.AddDatum(Circle(8));
  circles.AddDatum(Circle(4));

  std::cout << circles << std::endl;
  circles.SelectionSort();
  std::cout << circles << std::endl;


  // >> Define an instance of Data of type MathVector
  math_vectors.AddDatum(MathVector(5,8));
  math_vectors.AddDatum(MathVector(-3,1));
  math_vectors.AddDatum(MathVector(16,-2));

  std::cout << math_vectors << std::endl;
  math_vectors.SelectionSort();
  std::cout << math_vectors << std::endl;
  */
  return 1;
}
