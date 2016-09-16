set terminal postscript eps
set output "times.eps"
set title 'Theoretical complexity'
set autoscale
set ylabel 'N'
set xlabel 't'
f(x) = a*x + b
fit f(x) 'times' using 1:2 via a,b
plot "times" using 1:2  title "N vs execution time",f(x) title "Fitted line f(x)=a*x+b" lt rgb "red"
