CFLAGS = -lm -ansi -pedantic-errors -Wall -Wstrict-prototypes
OBJ = function.o bisection.o main.o

main: $(OBJ)
	gcc $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm math $(OBJ)
