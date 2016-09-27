/* Header file for the Quicksort project*/

#ifndef HEADER_FILE
#define HEADER_FILE


#define TABSIZE  20000

float table[TABSIZE];
void swap(float tab[], int i, int j);
void print_tab(float tab[], int left, int right);
void quicksort(float tab[],int left, int right);

#endif

