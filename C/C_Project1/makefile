C = gcc # the compiler we use
CFLAGS  = -Wall -pedantic -c # options for object compilation
LDFLAGS =  # options for link edition
.PHONY: clean fclean plot RunExample
all : RunExample plot
#target: dependencies
#<TAB> command(s)


SortBigTable.out: project1.o  functions.o main.h
	$(C) -o  SortBigTable.out project1.o functions.o $(LDFLAGS)
example.out: example.o  functions.o main.h
	$(C) -o  example.out example.o functions.o $(LDFLAGS)

functions.o: functions.c
	$(C) $(CFLAGS)  functions.c
project1.o: project1.c main.h
	$(C) $(CFLAGS)  project1.c
example.o: example.c main.h
	$(C) $(CFLAGS)  example.c


# clean functions
clean:
	rm -f *.o *.mod *~ *.eps *.dat 
fclean: clean
	rm -f SortBigTable.out example.out
plot: SortBigTable.out plot_sort.gnuplot plotSort.sh
	sh plotSort.sh
	echo "Two plots illustrating the sorting was complete have been generated on Sorted.eps and withoutSorting.eps"
RunExample: example.out
	./example.out

