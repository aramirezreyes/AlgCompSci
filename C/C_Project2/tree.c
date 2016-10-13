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



/* intended to obtain the maximum of the list that is different from the other */
void get_next_max(float *tab, float *new_val, int *idx){
  float tmp;
  int id;
  *new_val = 0;
  for(id=0;id<127;id++){   /* 127 correct this shit; the condition is bad */
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

/* void create_ordered_tree() */  

int main(void){
  char test[300]="Bottom. What is Pyramus? A lover or a tyrant?Quince. A lover that kills himself, most gallant, for love.Bottom. That will ask some tears in the true performing of it. If I do it, let t... ";
  float *oc,nueval=0;
  int  indice=0;
  bamboo_t tree;
  oc = build_dictionary(test);
  get_next_max(oc, &nueval,&indice);
  tree = (bamboo_t) malloc(sizeof(struct bamboo_s));
 
  tree->symbol = indice;
  tree->freq = nueval;
  while(nueval!=0){
    bamboo_t newLeaf;
    get_next_max(oc, &nueval,&indice);
    newLeaf = (bamboo_t) malloc(sizeof(struct bamboo_s));
    newLeaf->symbol = indice;
    newLeaf->freq = nueval;
    printf("Símbolo: %c, índice: %d, frecuencia: %f \n",indice, indice, nueval); 
    tree->next = newLeaf;
  }
 

  return 0;
}
