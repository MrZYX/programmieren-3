#include <sstream>
#include <iomanip>
#include <locale>
#include "CartItem.h"

using namespace std;

unsigned int CartItem::lastItemId = 0;

CartItem::CartItem(string name, double pricePerUnit, unsigned int quantity) {
  this->itemId = ++lastItemId;
  setName(name);
  setPricePerUnit(pricePerUnit);
  setQuantity(quantity);
}

CartItem::CartItem(const CartItem& item) {
  this->itemId = item.getItemId();
  setName(item.getName());
  setPricePerUnit(item.getPricePerUnit());
  setQuantity(item.getQuantity());
}

unsigned int CartItem::getItemId() const {
  return this->itemId;
}

string CartItem::getName() const {
  return this->name;
}

void CartItem::setName(string name) {
  this->name = name;
}

double CartItem::getPricePerUnit() const {
  return this->pricePerUnit;
}

void CartItem::setPricePerUnit(double pricePerUnit) {
  this->pricePerUnit = pricePerUnit;
}

unsigned int CartItem::getQuantity() const {
  return this->quantity;
}

void CartItem::setQuantity(unsigned int quantity) {
  this->quantity = quantity;
}


double CartItem::getCost() const {
  return this->quantity*this->pricePerUnit;
}

string CartItem::toString() const {
  ostringstream os;
  //os.imbue(locale(""));
  os << fixed << setprecision(2);
  //os << os.getloc().name();
  os << setw(3)  << right << this->quantity;
  os << setw(3)  << left  << " x ";
  os << setw(CART_ITEM_WIDTH-22) << left  << this->name; //FIXME: alignment is wrong, non-ascii chars count as 2+
  os << setw(8)  << right << this->pricePerUnit;
  os << setw(8)  << right << this->getCost();
  os << endl;
  return os.str();
}


CartItem::~CartItem() {}
