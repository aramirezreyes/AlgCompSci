#include <stdio.h>


void circshift(int *p){
  *p = *p<<1  ;
}

int main(void){
  int a = 5;
  int *p; 
  p = &a;
  
  circshift(p);
  
  return *p;
}

