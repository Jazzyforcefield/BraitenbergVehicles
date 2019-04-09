#ifndef BEVERAGE_DECORATOR_H_
#define BEVERAGE_DECORATOR_H_

#include <iostream>
#include <string>

#include "beverage.h"

class BeverageDecorator : public Beverage {
  public:
    BeverageDecorator() : beverage_(nullptr) {}
    BeverageDecorator(Beverage * bev) : beverage_(bev) {}
    void Receipt() {
      std::cout << "Total = $" << get_cost() << std::endl;
    }
    float get_cost() {
      return cost_ + beverage_->get_cost();
    }
  protected:
    Beverage * beverage_{nullptr};
    float cost_;
  };

#endif /* BEVERAGE_DECORATOR_H_ */
