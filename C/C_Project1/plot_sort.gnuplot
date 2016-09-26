set terminal postscript eps
set output "withoutSorting.eps"
set title 'Table without sorting'
set autoscale
set ylabel 'Value'
set xlabel 'Index'
plot "data.dat" index 0 using 1  title "Index vs value"

set terminal postscript eps
set output "Sorted.eps"
set title 'Sorted table'
set autoscale
set ylabel 'Value'
set xlabel 'Index'
plot "data.dat" index 1 using 1  title "Index vs value"