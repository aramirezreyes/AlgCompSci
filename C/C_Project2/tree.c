#include <stdlib.h>
#include <stdio.h>



/* typedef struct polynom_t *polynom; */

/* struct polynom_t{ */
/*   int coef; */
/*   int power; */
/*   struct polynom_t *next; */
/* };	

		        */

int strleng(char *word){
  int ii = 1;
  while(*(word + ii) != '\0')
    ii++;
  return ii;
}


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
    char test[100]="Quisiera volver amarte, volver a quererte volver a tenerte cerca de mi, mis ojos lloran por ti";
    float *oc;
    oc = build_dictionary(test);
    return 0;
}
