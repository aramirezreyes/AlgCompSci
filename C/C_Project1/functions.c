#include <stdio.h>
#include "main.h"
#include <stdlib.h>

void swap(float tab[], int i, int j){
  float tmp;
  tmp = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp;
}

void print_tab(float tab[], int left, int right){
  int idx;
  for (idx=left;idx<right;idx++)
    printf("%f\n",tab[idx]);
}

void quicksort(float tab[], int left, int right){
  int p_id,down=left,up=right;


  p_id = left  + (right-left)*((float)rand()/(float)(RAND_MAX)); 

  /* print_tab(table,0,TABSIZE); */
  /* printf("Pivote = %d\n, Nueva tabla:\n",p_id); */
  while (up>down){
    if(tab[down]<tab[p_id]){
      down++;}
    if(tab[up]>=tab[p_id]){
      up--;}
    if(tab[down]>tab[up]){
      swap(tab,down,up);}
  }
  swap(tab,p_id,down);
  p_id = down;

  if ((p_id)!=left)
    quicksort(tab,left,(p_id-1));
  if ((p_id)!=right)
    quicksort(tab,(p_id+1),right);
  

}

