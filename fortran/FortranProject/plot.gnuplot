set terminal postscript eps
set output "plot4.eps"
set title 'Numerical method'
#set autoscale
set xrange [0:1]
set ylabel 'X'
set xlabel 'U(x)'
plot "data" using 1:2  title "Method"
