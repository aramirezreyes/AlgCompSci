# include <stdio.h>
# define GPI_SIZE 3


struct GPI {
unsigned long digits[GPI_SIZE];
};

struct GPI GPI_ADD(struct GPI n1, struct GPI n2){
  int ii = 0;
  int c = 0;
  struct GPI sum;
  sum.digits[0] = 0;
  for (ii=0; ii<GPI_SIZE;ii++){
    sum.digits[ii] += (n1.digits[ii] + n2.digits[ii]);
    if (((n1.digits[ii]+n2.digits[ii]) <= n1.digits[ii]) || ((n1.digits[ii]+n2.digits[ii]) <= n2.digits[ii])){
      c = 1;
    }
    if (c==1){
      sum.digits[ii]++;
      c=0;
    }}
    return sum;
  }

int main(void){
  int ii = 0;
  struct GPI num1 = {{1213344,12342345435,12342334534}},num2 = {{12412334, 64164631,6431654}};
  struct GPI sum = GPI_ADD(num1,num2);
  for (ii=0;ii<GPI_SIZE;ii++)
    printf("%lu",sum.digits[ii]);
   
}
