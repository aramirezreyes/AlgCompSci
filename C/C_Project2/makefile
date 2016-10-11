C = gcc # the compiler we use
CFLAGS  = -Wall -pedantic -c # options for object compilation
LDFLAGS =  # options for link edition
.PHONY: clean fclean plot RunExample
all : Project2.out
#target: dependencies
#<TAB> command(s)


Project2.out: tree.out  tree.o
	$(C) -o  Project2.out tree.o $(LDFLAGS)
tree.out: tree.o main.h
	$(C) -o  tree.out tree.o $(LDFLAGS)
tree.o: tree.c main.h
	$(C) $(CFLAGS)  tree.c


# clean functions
clean:
	rm -f *.o *.mod *~ *.eps *.dat 
fclean: clean
	rm -f Project.out 


