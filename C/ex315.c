#include <stdio.h>
#include <stdlib.h>


int strleng(char *word){
  int ii = 1;
  while(*(word + ii) != '\0')
    ii++;
  return ii;
}


int main(void){
  char A[30] = "Hi, how are you?  ", B[30]="I am fine, thank you",*cat;
  int l1,l2,ii;
  l1 = strleng(A);
  l2 = strleng(B);  
  cat = (char*) malloc(((l1+l2)*sizeof(char)+1));
  for (ii=1;ii<=(l1);ii++){
    cat[ii-1] = A[ii-1];
}
  for (ii=l1;ii<=(l1+l2);ii++){
    cat[ii-1] = B[ii-l1];
}	       
  printf("%s\n",cat);
  return 0;
}
