#include <iostream>
#include "ShoppingCart.h"
#include "CartItem.h"

using namespace std;

int main(void) {
  ShoppingCart* cart = new ShoppingCart();
  cart->add(CartItem("Hundefutter", 3.20, 6));
  cart->add(CartItem("Kekse", 1.59, 4));
  cart->add(CartItem("Milch", 0.69, 1));
  cart->add(CartItem("Erdbeerkonfitüre", 2.19, 3));
  
  cout << cart->toString();

  cout << endl << endl;

  unsigned int* itemIds = cart->getItemIds();
  for (unsigned int i = 0; i < cart->getNumberOfItems(); i++) {
  	cout << itemIds[i] << " ";
  	cout << cart->getItemById(itemIds[i])->getName() << endl;
  }  

  delete[] itemIds;
  delete cart;
  
  return 0;
}