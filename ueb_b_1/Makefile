CPPARGS = -pedantic-errors -Wall --ansi -g

buyStuff: buyStuff.o ShoppingCart.o CartItem.o
	g++ $(CPPARGS) -o $@ $^

buyStuff.o: buyStuff.cc ShoppingCart.h CartItem.h
	g++ $(CPPARGS) -c $<

ShoppingCart.o: ShoppingCart.cc ShoppingCart.h CartItem.h
	g++ $(CPPARGS) -c $<

CartItem.o: CartItem.cc CartItem.h
	g++ $(CPPARGS) -c $<
