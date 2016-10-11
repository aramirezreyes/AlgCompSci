#include <stdio.h>
#include <stdlib.h>


struct path_table{
  char pth[800];
  struct path_table *next;
};

void filldirs(tab)
  char * pth;
  char bffr[100];
  int ii,jj;
  pth = getenv ("PATH");
  if (pth!=NULL){
    ii = 0;
    jj = 0;
    while(pth[ii]!="\0"){
      if (pth[ii]==":"){
	jj = 0;
	
      }
      bfrr[jj] = pth[ii];
      jj++;
      ii++;
      
    }
    
  }
    

}

int main(void){
  return 0;
}
