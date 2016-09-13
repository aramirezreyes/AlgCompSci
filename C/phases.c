/*------------------------------
A first program
---------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 12
int foo = 5;
int tom = 4;
const int bar = 5;
char a = 'k';
float b = 5.5;


extern int gee;
int main()
{
  int bzu;             /*declaration and definition of bzu*/
  int biz=3,buz;
  const int cte = 0;
  static raf = 3;
  bzu = MAX;
  printf("Hello : %d\n", foo + bar + bzu);
  exit(EXIT_SUCCESS);
}
