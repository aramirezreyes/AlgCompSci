# include <stdio.h>
# define CTE 3000000.134513
int main()
{
  float x=CTE;
  printf("%f\n%f\n",x,x+1);
  while (x != (x+1))
    {
      x=x+CTE;
      printf("New loop\n%f\n%f\n",x,x+1);
    }
  return 0;
}
