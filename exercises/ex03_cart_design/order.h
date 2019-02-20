#ifndef ORDER_H_
#define ORDER_H_

#include "cart_contents.h"

// An order is the combination of a cart and tax
// different states apply different salesTax rates.
class Order {
public:
  Order(CartContents c, float t);
  float OrderTotal();

private:
  CartContents cart;
  float tax;

};

#endif
