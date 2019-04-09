#ifndef WHIP_H_
#define WHIP_H_

#include <iostream>
#include <string>
#include <vector>

#include "beverage_decorator.h"

class Whip : public BeverageDecorator {
  public:
    Whip(Beverage* bev) : BeverageDecorator(bev) {
      cost_ = .50;
    }
    void Describe() {
      std::cout << "Whip ";
      beverage_->Describe();
    }
  };

#endif /* WHIP_H */
