/*Project 1 of C - Argel Ram'irez Reyes
This program implements the QuickSort algorithm described in the lecture notes.
This is the main file and it should be packaged with it's corresponding header files and complementary programs.
 */


#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void swap(float tab[], int i, int j){
  float tmp;
  tmp = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp;
}

int print_tab(float tab[], int left, int right){
  int idx;
  for (idx=left;idx<right;idx++)
    printf("%f\n",tab[idx]);
}

void quicksort(float tab[], int left, int right){
  int p_id,down=left,up=right;
  float p;

  p_id = left + (float)rand()/(float)(RAND_MAX/(right-left));
  p = tab[p_id];
  /* print_tab(table,0,TABSIZE); */
  printf("Pivote = %d\n, Nueva tabla:\n",p_id);
  while (up>down){
    while(tab[down]<p)
      down++;
    while(tab[up]>=p)
      up--;
    break;
  }
  if(tab[down]<tab[up])
    swap(tab,down,up);
  swap(tab,p_id,down);
  /* print_tab(table,0,TABSIZE); */
  /* printf("Pivote = %d\n, Nueva tabla:\n",p_id); */
  printf("Pivote = %d, Down: %d, Up: %d\n",p_id,down,up);
  p_id = down;

  if (p_id!=left)
    quicksort(tab,0,(p_id));
  if (p_id!=right)
    quicksort(tab,(p_id),TABSIZE);
  

}




int main(void){
  int ii;
  int rnd;
  srand((unsigned int) time(NULL));
  /*Inizialises the table*/
  for (ii=1;ii<TABSIZE;ii++){
    rnd  = (float)rand()/(float)(RAND_MAX/100);
    table[ii] = rnd;
  }
  
  quicksort(table,0,TABSIZE);
  

  return 0;
}
