set terminal postscript eps
set output "plot4.eps"
set title 'Numerical method'

set xrange [0:1]
set output "plot4.eps"
set xlabel 'U(x)'
plot "data" using 1:2  title "Method"
