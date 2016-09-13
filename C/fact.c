 #include <stdio.h>
 unsigned int  fact (unsigned int n)
  {
    unsigned int i = 1, res = 1;
    while (i <=  n)
      res = res  * i++;
    return res;
  }

int main(){
printf("Hello : %d\n", fact(10));
  return 0;
}
