#include <stdio.h>

int main(void){

  char string[18] = "Hi, how are you?";
  int ii = 1;
  while(*(string + ii) != '\0')
    ii++;
  return ii;
}
