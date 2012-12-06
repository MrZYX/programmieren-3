#include <sstream>
#include <iomanip>
#include "ShoppingCart.h"
#include "CartItem.h"

using namespace std;

ShoppingCart::ShoppingCart() {}

void ShoppingCart::add(const CartItem& item) {
  this->items.push_back(item);
}

double ShoppingCart::getTotalCost() const {
  double cost = 0;
  for (unsigned int i=0; i<this->items.size(); i++) {
    cost += this->items[i].getCost();
  }
  return cost;
}

unsigned int ShoppingCart::getNumberOfItems() const {
  return this->items.size();
}

CartItem ShoppingCart::getItem(unsigned int i) const {
  return this->items[i];
}

const CartItem* ShoppingCart::getItemById(unsigned int id) const {
  for (unsigned int i = 0; i < items.size(); i++) {
    if (items[i].getItemId() == id) {
      return &(items[i]);
    }
  }

  return NULL;
}

unsigned int* ShoppingCart::getItemIds() const {
  unsigned int* itemIds = new unsigned int[items.size()];
  for (unsigned int i = 0; i < items.size(); i++) {
    itemIds[i] = items[i].getItemId();
  }

  return itemIds;
}

string ShoppingCart::toString() const {
  ostringstream os;
  os << fixed << setprecision(2);
  for (unsigned int i = 0; i < items.size(); i++) {
    os << items[i].toString();
  }
  os << endl;
  os << setw(12) << left << "Total:";
  os << setw(CART_ITEM_WIDTH-12) << right << this->getTotalCost() << endl;
  return os.str();
}

ShoppingCart::~ShoppingCart() {}
