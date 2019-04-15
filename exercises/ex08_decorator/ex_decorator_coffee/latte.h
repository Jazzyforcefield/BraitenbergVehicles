#ifndef LATTE_H_
#define LATTE_H_

#include <iostream>
#include <string>

#include "beverage.h"

class Latte : public Beverage {
  public:
    Latte() : Beverage(3.50, "Latte") {}
    void Describe() {
      std::cout << "latte." << std::endl;
    }
    void Receipt() {
      std::cout << "Total is $" << get_cost() << std::endl;
    }
  };

#endif /* LATTE_H_ */
