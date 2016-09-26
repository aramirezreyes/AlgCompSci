C = gcc # the compiler we use
CFLAGS  = -Wall -pedantic -c # options for object compilation
LDFLAGS =  # options for link edition
.PHONY: clean fclean plot plot_several plot_times
all : SortBigTable.out
#target: dependencies
#<TAB> command(s)
SortBigTable.out: project1.o  functions.o main.h
	$(C) -o  SortBigTable.out project1.o functions.o $(LDFLAGS)

functions.o: functions.c
	$(C) $(CFLAGS)  functions.c
project1.o: project1.c main.h
	$(C) $(CFLAGS)  project1.c

# clean functions
clean:
	rm -f *.o *.mod *~ *.eps data times *.log
fclean: clean
	rm -f SortBigTable.out
plot: data
	gnuplot plot.gnuplot
data: catenaire.out
			(echo 100 | ./catenaire.out) > data
plot_several: diferentFunctions.sh
	bash diferentFunctions.sh
plot_times: catenaire2.out plot_times.gnuplot plot_times.sh
	bash plot_times.sh
