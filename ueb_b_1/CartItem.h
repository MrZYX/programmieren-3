#ifndef CART_ITEM_H
#define CART_ITEM_H

#include <string>

#define CART_ITEM_WIDTH 52

using namespace std;

class CartItem {
  private:
    unsigned int itemId;
    string name;
    double pricePerUnit;
    unsigned int quantity;
    static unsigned int lastItemId;
  public:
    CartItem(const string name, double pricePerUnit, unsigned int quantity);
    CartItem(const CartItem& item);
    unsigned int getItemId() const;
    string getName() const;
    void setName(string name);
    double getPricePerUnit() const;
    void setPricePerUnit(double pricePerUnit);
    unsigned int getQuantity() const;
    void setQuantity(unsigned int quantity);
    double getCost() const;
    string toString() const;
    ~CartItem();
};

#endif
