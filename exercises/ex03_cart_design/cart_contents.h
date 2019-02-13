#ifndef CART_CONTENTS_H_
#define CART_CONTENTS_H_

#include "cart_entry.h"

// A collection of elements in a cart
// CartContents "has a" CartEntry - using composition
class CartContents{
public:
  int item_count; // number of elements in cart
  CartEntry* items;
};

#endif
