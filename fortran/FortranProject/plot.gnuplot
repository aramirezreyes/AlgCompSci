set terminal postscript eps
set output "plot4.eps"
set title 'Numerical method '
#set autoscale
f(x) = (x*x)/2 - x/2
set xrange [0:1]
set ylabel 'X'
set xlabel 'U(x)'
plot f(x) title "Exact solution", "data" using 1:2  title "Method"
