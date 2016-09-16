for (( i=1; i<=1000000; i=i+1000 ))
do
 (echo $i | ./catenaire2.out) >> times
done
gnuplot plot_times.gnuplot
