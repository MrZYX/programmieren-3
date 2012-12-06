#include <iostream>
#include <string>
#include "ShoppingCart.h"
#include "CartItem.h"

using namespace std;

int main(void) {
  ShoppingCart cart;
  //cout.imbue(locale("en_US.UTF-8"));
  cart.add(CartItem("Dog food", 3.20, 6));
  cart.add(CartItem("Cookies", 1.59, 4));
  cart.add(CartItem("Milk", 0.69, 1));
  cart.add(CartItem("Strawberry marmelade", 2.19, 3));
  
  cout << cart.toString();

  cout << endl << endl;

  unsigned int* itemIds = cart.getItemIds();
  for (unsigned int i = 0; i < cart.getNumberOfItems(); i++) {
  	cout << itemIds[i] << " ";
  	cout << cart.getItemById(itemIds[i])->getName() << endl;
  }  

  delete[] itemIds;
  
  return 0;
}