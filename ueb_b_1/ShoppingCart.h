#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <vector>
#include <string>
#include "CartItem.h"

using namespace std;

class ShoppingCart {
  private:
    std::vector<CartItem> items;
  public:
    ShoppingCart();
    void add(const CartItem& item);
    double getTotalCost() const;
    unsigned int getNumberOfItems() const;
    CartItem getItem(unsigned int i) const;
    const CartItem* getItemById(unsigned int id) const;
    unsigned int* getItemIds() const;
    string toString() const;
    ~ShoppingCart();
};

#endif
