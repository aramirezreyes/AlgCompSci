#include <stdio.h>
/* This function intends to compute the cross product of a vector in wich aeac vector is of the type int[3] */
int main(void){
  int A[3]={0,0,1},B[3]={0,1,0},C[3]={1,1,1};



  void cross_product(int *A, int *B, int *C){
    C[0] = A[1]*B[2] - A[2]*B[1];
    C[1] =A[2]*B[0] - A[0]*B[2];
    C[2] =A[0]*B[1] - A[1]*B[0];
  }
  cross_product(A,B,A);

  printf("The result of the cross product is: [%d,%d,%d] \n",A[0],A[1],A[2]);
  printf("The result of the cross product is: [%d,%d,%d] \n",B[0],B[1],B[2]);


  return 0;
}
