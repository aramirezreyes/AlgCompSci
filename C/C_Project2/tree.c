#include <stdlib.h>
#include <stdio.h>



 typedef struct leaf_s *leaf_t;

/* struct polynom_t{ */
/*   int coef; */
/*   int power; */
/*   struct polynom_t *next; */
/* };	*/

struct leaf_s{
  char symbol;
  float freq;
};

struct bamboo_s{
  leaf_t leaf;
  struct bamboo_s *next;
  };


/* just a function i will use later; it measures the length of the text */
int strleng(char *word){
  int ii = 1;
  while(*(word + ii) != '\0')
    ii++;
  return ii;
}


/* intended to obtain the maximum of the list that is different from the other */
void get_next_max(int prev_idx,float *tab, float *new_val, int *idx){
  /* float max=1; */
  int id;
  *new_val = 0;
  for(id=0;id<127;id++){   /* correct this shit; the condition is bad */
    if ((id!=prev_idx) && (*new_val<=tab[id]))
	     *new_val = tab[id];
    *idx = id;
}

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
  

int main(void){
char test[300]="Bottom. What is Pyramus? A lover or a tyrant?Quince. A lover that kills himself, most gallant, for love.Bottom. That will ask some tears in the true performing of it. If I do it, let t... ";
float *oc, *nv,nueval=0;
int  *id,p_id,indice=0;
&nueval;
&indice;
oc = build_dictionary(test);
p_id=0;
get_next_max(p_id,oc, &nueval,&indice);

return 0;
}
