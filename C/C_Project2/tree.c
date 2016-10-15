#include <stdlib.h>
#include <stdio.h>
#include "main.h"




/* just a function i will use later; it measures the length of the text */
int strleng(char *word){
  int ii = 1;
  while(*(word + ii) != '\0')
    ii++;
  return ii;
}

/* int not_in(*float tab,int num_elem,float to_prove){ */
/*   int not = 1,j; */
/*   for (j=0;j<num_elem,j++){ */
/*     if ((tab+j)==to_prove){ */
/*       not = 0; */
/*       break; */
/*     } */
/*   }return not; */
/* } */


/* intended to obtain the maximum of the list that is different from the other */
void get_next_max(float *tab, float *new_val, int *idx){
  float tmp;
  int id;
  *new_val = 0;
  for(id=0;id<127;id++){   
    /* printf("El viejo valor es: %f, y el actual es: %f\n",prev_val,tab[id]); */
    if (*new_val<=tab[id]){
	     *idx = id;
	     tmp = tab[id];
	     *new_val = tmp;
	      /* printf("Cambiado el indice a %d y la freq a %f\n",*idx,*new_val);  */
      }
  }
  tab[*idx] = 0;
}


/* intended to obtain the maximum of the list that is different from the other */
void get_next_min(float *tab, float *new_val, int *idx){
  float tmp;
  int id;
  *new_val = 1;
  for(id=0;id<127;id++){   
    /* printf("El viejo valor es: %f, y el actual es: %f\n",prev_val,tab[id]); */
    if ((*new_val>=tab[id]) & (tab[id]>0)){
	     *idx = id;
	     tmp = tab[id];
	     *new_val = tmp;
	      /* printf("Cambiado el indice a %d y la freq a %f\n",*idx,*new_val); */  
      }
  }
  tab[*idx] = 1;
}


/* To get the relative frequencies of the characters */
float * build_dictionary(char *str){
  static float occur[127]={0};
int i=0,tmp_char;
float total = strleng(str);

  for(i=0;str[i];i++){
    tmp_char = str[i];
    occur[tmp_char] = occur[tmp_char] + 1/total;;
  }
  return occur;
}

void create_ordered_tree(float *oc){
  float nueval=0;
  int  indice=0;
  bamboo_t tree;
  get_next_min(oc, &nueval,&indice);
  tree = (bamboo_t) malloc(sizeof(struct bamboo_s));
 
  tree->symbol = indice;
  tree->freq = nueval;
  while(nueval!=1){ /* This condition leaves the last value without use beacuse it is not the real value */
    bamboo_t newLeaf;
    get_next_min(oc, &nueval,&indice);
    newLeaf = (bamboo_t) malloc(sizeof(struct bamboo_s));
    newLeaf->symbol = indice;
    newLeaf->freq = nueval;
    printf("Símbolo: %c, índice: %d, frecuencia: %f \n",indice, indice, nueval); 
    tree->next = newLeaf;
  }
}

int main(void){
  char test[300]="Bottom. What is Pyramus? A lover or a tyrant?Quince. A lover that kills himself, most gallant, for love.Bottom. That will ask some tears in the true performing of it. If I do it, let t... ";
  float *oc;
  oc = build_dictionary(test);
  create_ordered_tree(oc);
  return 0;
}
