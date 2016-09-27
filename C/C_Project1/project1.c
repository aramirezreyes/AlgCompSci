/*Project 1 of C - Argel Ram'irez Reyes
This program implements the QuickSort algorithm described in the lecture notes.
This is the main file and it should be packaged with it's corresponding header files and complementary programs.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"



int main(void){
  int ii;
  float rnd;
  srand((unsigned int) time(NULL));
  /*Inizialises the table*/
  for (ii=0;ii<=TABSIZE;ii++){
    rnd  = (float)rand()/(float)(RAND_MAX/100);
    table[ii] = rnd;
  }
/* Prints the table, for big tables this main program is to be used only trough make plot; because it will flood the standard output */
  print_tab(table,0,TABSIZE);
  printf("\n\n\n");
  quicksort(table,0,TABSIZE);
  print_tab(table,0,TABSIZE);

  return 0;
}
