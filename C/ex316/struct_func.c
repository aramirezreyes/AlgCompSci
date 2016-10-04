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
  }printf(" %d*x**%d \n ",P2->coef,P2->power);
}

polynom populate_polynom(void){
 polynom P2;
 P2 = (polynom) malloc(sizeof(struct polynom_t));
 polynom P3;
 P3 = (polynom) malloc(sizeof(struct polynom_t));
 polynom P4;
 P4 = (polynom) malloc(sizeof(struct polynom_t));

 P2->coef = 1;
 P2->power = 3;
 P2->next = P3,
 P3->coef = 1;
 P3->power = 4;
 P3->next = P4;
 P4->coef = 3;
 P4->power = 5;
 P4->next=NULL;

 return P2;
}


int main(void){

 polynom P2;
 P2 = (polynom) malloc(sizeof(struct polynom_t));

 P2 = populate_polynom();

 print_polynom(P2);

    
 return 0;
}
