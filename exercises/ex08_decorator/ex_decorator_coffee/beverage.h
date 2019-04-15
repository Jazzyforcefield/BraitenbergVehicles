#ifndef BEVERAGE_H_
#define BEVERAGE_H_

#include <iostream>
#include <string>

class Beverage {
  public:
    Beverage() : cost_(2.50), description_("Beverage") {}
    Beverage(float cost, std::string desc) : cost_(cost), description_(desc) {}

    virtual void Describe() = 0;
    virtual void Receipt() = 0;
    virtual float get_cost() { return cost_; }
    virtual std::string get_description() { return description_; }
  protected:
    float cost_;
    std::string description_;
  };

#endif /* BEVERAGE_H_ */
