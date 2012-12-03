#ifndef CART_ITEM_H
#define CART_ITEM_H

#include <string>

using namespace std;

class CartItem {
  private:
    unsigned int itemId;
    char* name;
    double pricePerUnit;
    unsigned int quantity;
    static unsigned int lastItemId;
  public:
    CartItem(const char* name, double pricePerUnit, unsigned int quantity);
    CartItem(const CartItem& item);
    unsigned int getItemId() const;
    char* getName() const;
    void setName(const char* name);
    double getPricePerUnit() const;
    void setPricePerUnit(double pricePerUnit);
    unsigned int getQuantity() const;
    void setQuantity(unsigned int quantity);
    double getCost() const;
    string toString() const;
    ~CartItem();
};

#endif
