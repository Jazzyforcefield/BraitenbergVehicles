#ifndef COFFEE_H_
#define COFFEE_H_

#include <iostream>
#include <string>
#include <vector>

#include "beverage.h"

class Coffee : public Beverage {
  public:
    Coffee() : Beverage(2.50, "Coffee") {}
    void Describe() {
      std::cout << "coffee." << std::endl;
    }
    void Receipt() {
      std::cout << "Total is $" << get_cost() << std::endl;
    }
  };

#endif /* COFFEE_H_ */
