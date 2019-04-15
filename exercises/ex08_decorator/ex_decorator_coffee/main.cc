#include <iostream>
#include "coffee.h"
#include "latte.h"
#include "cream.h"
#include "whip.h"
#include "mocha.h"

int main() {
  Beverage * coffee = new Coffee;
  coffee = new Cream(coffee);
  coffee->Describe();
  coffee->Receipt();

  Beverage * latte = new Latte;
  latte = new Whip(latte);
  latte = new Mocha(latte);
  latte = new Mocha(latte);
  latte->Describe();
  latte->Receipt();
}
