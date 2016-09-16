 # This creates different plots, by changing the definition of the funcion in function.f90
#!/bin/bash

cp function.f90 functionBk.f90
cp plot.gnuplot plotBk.gnuplot

 MyFile=function.f90
 MyPlotter=plot.gnuplot

sed -i '7s/.*/f = -x /' $MyFile
sed -i '5s/.*/ /' $MyPlotter
sed -i '2s/.*/set output \"plot2.eps\"  /' $MyPlotter
sed -i '9s/.*/plot \"data\" using 1:2  title \"Method\" /' $MyPlotter

make
(echo "100" | ./catenaire.out) > data
make plot

sed -i '7s/.*/f = -\(x-0.5\)**2 /' $MyFile
sed -i '5s/.*/ /' $MyPlotter
sed -i '2s/.*/set output \"plot3.eps\" /' $MyPlotter
sed -i '9s/.*/plot \"data\" using 1:2  title \"Method\" /' $MyPlotter

make
(echo "100" | ./catenaire.out) > data
make plot



sed -i '7s/.*/f = -1*cos\(x\) /' $MyFile
sed -i '5s/.*/ /' $MyPlotter
sed -i '2s/.*/set output \"plot4.eps\" /' $MyPlotter
sed -i '9s/.*/plot \"data\" using 1:2  title \"Method\" /' $MyPlotter
make
(echo "100" | ./catenaire.out) > data
make plot


cp functionBk.f90 function.f90
cp plotBk.gnuplot plot.gnuplot
rm plotBk.gnuplot
rm functionBk.f90
make
