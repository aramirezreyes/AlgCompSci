/*Project 1 of C - Argel Ram'irez Reyes
This program implements the QuickSort algorithm described in the lecture notes.
This is the main file and it should be packaged with it's corresponding header files and complementary programs.
 */

/* EXAMPLE OF THE PROJECT */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"



int main(void){
  int ii;
  float rnd1,rnd2,rnd3,rnd4,sum;
  long double sum2;
  srand((unsigned int) time(NULL));
  /*Inizialises the table*/
  for (ii=0;ii<=((TABSIZE/4)-3);ii++){
    rnd1  = (float)rand()/(float)(RAND_MAX/1112465223);
    rnd2  = (float)rand()/(float)(RAND_MAX/5);
    rnd3  = (float)rand()/(float)(RAND_MAX/5000);
    rnd4  = (float)rand()/(float)(RAND_MAX/1000000);
    table[4*ii] = rnd1;
    table[(4*ii)+1] = rnd2;
    table[(4*ii)+2] = rnd3;
    table[(4*ii)+3] = rnd4;
  }
  /* Two sums, sum is a float and sum2 is a long double */
  sum = 0;
  sum2 = 0;
  for (ii=0;ii<=(20000);ii++){
    sum += table[ii];
    sum2 += table[ii];
  }
 printf("The sum without sorting is: %f \n",sum);
 printf("The sum without sorting using long double is: %Lf \n",sum2);
 quicksort(table,0,TABSIZE);
 sum = 0;
 sum2 = 0;
 for (ii=0;ii<=(TABSIZE);ii++){
   sum += table[ii];
   sum2 += table[ii];
 }
 printf("The sum after sorting is: %f \n",sum);
 printf("The sum after sorting using long double is: %Lf \n",sum2);
  return 0;
}
