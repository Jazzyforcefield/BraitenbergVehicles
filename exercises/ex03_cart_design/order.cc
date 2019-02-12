#include "order.h"

Order::Order(CartContents c, float t ) : cart(c), tax(t) {
}

float Order::OrderTotal() {
  float cart_total = 0;
  for (int i=0; i < cart.item_count; i++) {
    cart_total += cart.items[i].price * cart.items[i].quantity;
  }
  cart_total += cart_total * tax;
  return cart_total;
}
