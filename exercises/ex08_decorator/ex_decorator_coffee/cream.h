#ifndef CREAM_H_
#define CREAM_H_

#include <iostream>
#include <string>

#include "beverage_decorator.h"

class Cream : public BeverageDecorator {
  public:
    Cream(Beverage* bev) : BeverageDecorator(bev) {
      cost_ = 0;
    }
    void Describe() {
      std::cout << "Cream ";
      beverage_->Describe();
    }
  };

#endif /* CREAM_H */
