#!/bin/bash
for (( ii=1; ii<=1000000; ii=ii+1000 ))
do
 (echo $ii | ./catenaire2.out) >> times
done
gnuplot plot_times.gnuplot
