#!/bin/bash

(./SortBigTable.out)>data.dat

gnuplot plot_sort.gnuplot
