#include<stdio.h>
# define ISDIG_CAP(c) ((((c)>='0')&&((c)<='9'+'0'))||(((c)>='A')&&((c)<='Z')))
int main() {
   char c;
 
   printf("\nEnter The Character : ");
   scanf("%c", &c);
 
   /* while (c=getchar(),ISDIG_CAP(c))*/
   while ISDIG_CAP(getchar())
     printf("%s","True\n");
 
   return (0);
}
