#!/bin/bash


#his program calls SortBig table to ilustrate if it works. to do so, it saves the unsorted table and the sorted one into file data.dat and then it plots them using gnuplot through the file plot_sort.gnuplot

(./SortBigTable.out)>data.dat

gnuplot plot_sort.gnuplot
