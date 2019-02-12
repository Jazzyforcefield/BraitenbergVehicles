#include <iostream>

#include "cart_entry.h"
#include "cart_contents.h"
#include "order.h"

int main() {

  // Create an array of CartEntry's to put in the cart
  // Arbitrary values for price and quantity
  CartEntry in_cart[5];
  for (int i=0; i<5; i++) {
    in_cart[i].price = i*2;
    in_cart[i].quantity = i;
  }

  // Place the CartEntry array in a CartContents
  CartContents purchases;
  purchases.items = in_cart;
  purchases.item_count = 5;

  // Make this an order with associated tax
  Order order1(purchases, .077);

  // Get total price of order
  std::cout << '$' << order1.OrderTotal() << std::endl;

  return 0;
}
