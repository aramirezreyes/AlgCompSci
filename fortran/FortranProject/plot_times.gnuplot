set terminal postscript eps
set output "times.eps"
set title 'Theoretical complexity'
#set autoscale
set xrange [0:1]
set ylabel 'N'
set xlabel 't'
plot "times" using 1:2  title "N vs execution time"
