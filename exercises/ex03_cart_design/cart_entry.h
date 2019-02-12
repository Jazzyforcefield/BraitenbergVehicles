#ifndef CART_ENTRY_H_
#define CART_ENTRY_H_

// A class for a single element in a cart
class CartEntry {
public:
  float price;
  int quantity;
  CartEntry( float p=0, int q=0) : price(p), quantity(q) {}
};

#endif
