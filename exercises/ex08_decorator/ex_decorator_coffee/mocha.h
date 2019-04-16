#ifndef MOCHA_H_
#define MOCHA_H_

#include <iostream>
#include <string>

#include "beverage_decorator.h"

class Mocha : public BeverageDecorator {
  public:
    Mocha(Beverage* bev) : BeverageDecorator(bev) {
      cost_ = .75;
    }
    void Describe() {
      std::cout << "Mocha ";
      beverage_->Describe();
    }
  };

#endif /* MOCHA_H */
