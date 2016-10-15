C = gcc # the compiler we use
CFLAGS  = -Wall -pedantic -c -g # options for object compilation
LDFLAGS =  # options for link edition
.PHONY: clean fclean plot RunExample
all : Project2.out
#target: dependencies
#<TAB> command(s)


Project2.out: tree.o  tree.o create_strings.o encoder.o
	$(C) -o  Project2.out tree.o create_strings.o encoder.o $(LDFLAGS)
# tree.out: tree.o main.h
# 	$(C) -o  tree.out tree.o $(LDFLAGS)
# create_strings.out: create_strings.o main.h
# 	$(C) -o  create_strings.out create_strings.o $(LDFLAGS)
encoder: encoder.c
	$(C) $(CFLAGS) encoder.c
tree.o: tree.c main.h
	$(C) $(CFLAGS)  tree.c
create_strings.o: create_strings.c main.h
	$(C) $(CFLAGS)  create_strings.c 

# clean functions
clean:
	rm -f *.o *.mod 
fclean: clean
	rm -f Project2.out 


