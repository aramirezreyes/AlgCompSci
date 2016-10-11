# include <stdio.h>
# define TABSIZE 11

int count[TABSIZE];
char  c;
int ii;
int main(void){
  while (((c=getchar()))!= EOF){
    if ((c>='0') && (c<='9'))
      count[c - '0']++;
    else if (c=' ')
      count[10]++;
}
  for (ii=0;ii<=(TABSIZE-1);ii++){
    printf("The number of %d is: %d \n",ii,count[ii]);
}
  printf("The number of white spaces is: %d\n",count[10]);
}
