FORTRAN = gfortran # the compiler we use
CFLAGS  = -Wall -pedantic -c -Wno-unused-dummy-argument# options for object compilation
LDFLAGS =  # options for link edition
.PHONY: clean fclean plot plot_several
all : catenaire.out
#target: dependencies
#<TAB> command(s)
catenaire.out: solveSystem.o  function.o call_module.o
	$(FORTRAN) -o  catenaire.out solveSystem.o function.o call_module.o $(LDFLAGS)
catenaire2.out: solveSystem.o  function.o call_module2.o
		$(FORTRAN) -o  catenaire2.out solveSystem.o function.o call_module2.o $(LDFLAGS)
call_module.o: call_module.f90 function.mod solveSystem.mod
	$(FORTRAN) $(CFLAGS) call_module.f90
call_module2.o: call_module2.f90 function.mod solveSystem.mod
	$(FORTRAN) $(CFLAGS) call_module2.f90
solveSystem.o solveSystem.mod function.mod function.o: function.f90 solveSystem.f90
	$(FORTRAN) $(CFLAGS) function.f90 solveSystem.f90
# clean functions
clean:
	rm -f *.o *.mod *~ *.eps data times *.log *Bk*
fclean: clean
	rm -f catenaire.out catenaire2.out
plot:
	gnuplot plot.gnuplot
plot_several: diferentFunctions.sh
	sh diferentFunctions.sh
plot_times: catenaire2.out plot_times.sh plot_times.gnuplot
	sh plot_times.sh
