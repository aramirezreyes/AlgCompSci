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
    occur[tmp_char] = occur[tmp_char] + 1/total;
  }
  return occur;
}

/* TTTEEEEESTTIIIIIINNNNGGGG need to add an error catcher on file opening*/
float * build_dictionary_file(char *filename){
  FILE *ptr_file;
  char buf[64];
  int i,size=0,tmp_char;
  float total;
  static float occur[127] = {0};
  ptr_file = fopen(filename,"r");
  if (!ptr_file)
    printf("Failed to open file \"%s\"  ¿does it exist?\n",filename);
  fseek(ptr_file, 0L, SEEK_END);
  total = ftell(ptr_file);
  rewind(ptr_file);
  while(fgets(buf,sizeof(buf),ptr_file)!=NULL){
     printf("Leído: %s \n",buf); 
    for(i=0; (i<sizeof(buf)) ; i++){
      size++;
    tmp_char = buf[i];
     /* printf("Letra: %c, índice %d \n",buf[i],buf[i]);  */
    occur[tmp_char] = occur[tmp_char] + 1;
    }
  }
  for(i=0;i<127;i++){
    occur[i] = occur[i]/size;
    printf("Letra: %c, frecuencia %f \n",i,occur[i]);}
  rewind(ptr_file);
  return occur;
}
/* TTTEEEEESTTIIIIIINNNNGGGG*/



bamboo_t create_ordered_tree(float *oc){
  float nueval=0;
  int  indice=0;
  bamboo_t bamboo,root;
  get_next_min(oc, &nueval,&indice);
  bamboo = (bamboo_t) malloc(sizeof(struct bamboo_s));
  bamboo->tree = (tree_t) malloc(sizeof(struct tree_s)); 
  bamboo->tree->symbol = indice;
  bamboo->tree->freq = nueval;
  root = bamboo;
  while(nueval!=1){ /* This condition leaves the last value without use beacuse it is not the real value */
    bamboo_t newLeaf;
    get_next_min(oc, &nueval,&indice);
    newLeaf = (bamboo_t) malloc(sizeof(struct bamboo_s));
    newLeaf->tree = (tree_t) malloc(sizeof(struct tree_s));
    (newLeaf->tree)->symbol = indice;
    (newLeaf->tree)->freq = nueval;
    printf("Símbolo: %c, índice: %d, frecuencia: %f \n",indice, indice, nueval); 
    bamboo->next = newLeaf;
    bamboo = bamboo->next;
  }
  return root;
}
/* void decoder(char filename){ */
/*   char  *fileName, *outputFileName; */
/*   float *oc; */
/*   tree_t  tree; */
/*   bamboo_t  bamboo; */
/*   long int codes[127]={0}; */
/*   fileName = "text.txt"; */
/*   outputFileName = "output.txt"; */
/*   oc = build_dictionary_file(fileName); */
/*   printf("Done building table \n"); */
/*   bamboo =  create_ordered_tree(oc); */
/*   printf("Done building bamboo \n"); */
/*   tree = tree_generator(bamboo); */
/*   printf("Done building tree \n"); */
/*   free_bamboo(bamboo); */
/* } */


/* void save_table(*float table); */


int main(void){
  /* char test[300]="Bottom. What is Pyramus? A lover or a tyrant?Quince. A lover that kills himself, most gallant, for love.Bottom. That will ask some tears in the true performing of it. If I do it, let t... "; */
  char  *fileName, *outputFileName;
  float *oc;
  tree_t  tree;
  bamboo_t  bamboo;
  int codes[127]={0};
  fileName = "text.txt";
  outputFileName = "output.txt";
  oc = build_dictionary_file(fileName);
  printf("Done building table \n");
  bamboo =  create_ordered_tree(oc);
  printf("Done building bamboo \n");
  tree = tree_generator(bamboo);
  printf("Done building tree \n");
  free_bamboo(bamboo);
  code_generator(1,tree,codes,1);
  printf("Filled codes table\n");
  encode_file(fileName,outputFileName,codes);
  
  return 0;
}

