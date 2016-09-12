FORTRAN = gfortran # the compiler we use
CFLAGS  = -Wall -pedantic -c -Wno-unused-dummy-argument# options for object compilation
LDFLAGS =  # options for link edition
.PHONY: clean fclean
all : catenaire.out
#target: dependencies
#<TAB> command(s)
catenaire.out: function.o call_module.o
	$(FORTRAN) -o catenaire.out function.o call_module.o $(LDFLAGS)
call_module.o: call_module.f90 f_function.mod
	$(FORTRAN) $(CFLAGS) call_module.f90
f_function.mod function.o: function.f90
	$(FORTRAN) $(CFLAGS) function.f90
# clean functions
clean:
	rm -f *.o *.mod *~
fclean: clean
	rm -f catenaire.out
