#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "CartItem.h"

using namespace std;

unsigned int CartItem::lastItemId = 0;

CartItem::CartItem(const char* name, double pricePerUnit, unsigned int quantity) {
  this->itemId = ++lastItemId;
  this->name = NULL;
  setName(name);
  setPricePerUnit(pricePerUnit);
  setQuantity(quantity);
}

CartItem::CartItem(const CartItem& item) {
  this->itemId = item.itemId;
  this->name = NULL;
  setName(item.getName());
  setPricePerUnit(item.getPricePerUnit());
  setQuantity(item.getQuantity());
}

unsigned int CartItem::getItemId() const {
  return this->itemId;
}

char* CartItem::getName() const {
  return this->name;
}

void CartItem::setName(const char* name) {
  if (this->name != NULL) {
    free(this->name);
  }
  
  this->name = (char*) malloc((strlen(name)+1)*sizeof(*name));
  strcpy(this->name, name);
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

std::string CartItem::toString() const {
  ostringstream os;

  os << fixed << setprecision(2);// << setw(40);
  os << setw(3)  << right << this->quantity;
  os << setw(3)  << left  << " x ";
  os << setw(30) << left  << this->name; //FIXME: alignment is wrong, non-ascii chars count as 2+
  os << setw(8)  << right << this->pricePerUnit;
  os << setw(8)  << right << this->getCost();
  os << endl;
  return os.str();
}


CartItem::~CartItem() {
  if(this->name != NULL) {
    free((void*) this->name);
    this->name = NULL;
  }
}
