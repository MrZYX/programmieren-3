CFLAGS = -ansi -pedantic-errors -Wall -Wstrict-prototypes
OBJ = math.o summe.o differenz.o input.o

math: $(OBJ)
	gcc $(CFLAGS) -o math $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm math $(OBJ)
