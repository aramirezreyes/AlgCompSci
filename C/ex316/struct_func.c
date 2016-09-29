#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

void print_polynom(polynom P){

  polynom P2;
  P2 = (polynom) malloc(sizeof(struct polynom_t));
  P2 = P;
  printf("P(x) = ");
  while (P2->next){
    printf(" %d*x**%d + ",P2->coef,P2->power);
    P2 = (P2-> next);
  }
}

polynom populate_polynom(void){

 polynom P2;
 P2 = (polynom) malloc(sizeof(struct polynom_t));

 P2->coef = 1;
 P2->power = 3;
 P2->next = P2;
 P2->coef = 1;
 P2->power = 4;
 P2->next = P2;
 P2->coef = 3;
 P2->power = 5;
}


int main(void){

 polynom P;
 P = (polynom) malloc(sizeof(struct polynom_t));
 P = populate_polynom();

 print_polynom(P);

    
 return 0;
}
