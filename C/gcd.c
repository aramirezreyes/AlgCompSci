 #include <stdio.h>
unsigned int  gcd (unsigned int n1, unsigned int n2)
  {
    int div,rem;
    div = n1/n2;
    rem = n1-n2*div;
    if (rem>0){
      while (rem>0){
    n1 = n2;
    n2 = div;
    div = n1/n2;
    rem = n1-n2*div;    

      } /* End of while */
    } /* end of if*/
    return n2;
  }

int main(){
  int int1,int2;
  printf("Hello : introduce the biggest number\n");
   scanf("%d", &int1);
   printf("Enter the smaller number: \n ");
   scanf("%d", &int2);
   printf("The GCD is %d\n",gcd(int1,int2));
   
  return 0;
}
