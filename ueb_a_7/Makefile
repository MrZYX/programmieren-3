CFLAGS = -ansi -pedantic-errors -Wall -Wstrict-prototypes
objects = 

liste1endemain: liste1ende.o liste1endemain.o
	gcc $^ -o $@

%.o: %.c liste1ende.h
	gcc $(CFLAGS) -c $<

