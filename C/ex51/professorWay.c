#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

char ** dirs;
char * pth;
/* we are going to parse it three times: one to count the nu,ber of semicolons, n,after this we allocate the first table with n+2, on the second parsing we count the length of the strings, after this we do the second allocation for each element of the table, and in the third we copy the actual strings */


void filldirs(void){
  int ii,num_dirs;
  pth = getenv("PATH");
  assert(*pth != "\0");
  for(ii = 0,num_dirs=1;pth[ii];ii++){
    if (pth[ii]==':'){
      num_dirs++;
      pth[ii]='\0';
    }}
    dirs = (char**) malloc((num_dirs+1) * sizeof(char*));
    dirs[num_dirs] = NULL;
    num_dirs--;
    for (ii=0;num_dirs!=-1;num_dirs--){
      dirs[num_dirs] = pth + ii;
      printf("%s\n",pth + ii);
      while(pth[ii])
	ii++;
      ii++;}
  }
      
  void which(char **dirs){
    ii = 0;
    tmp = dirs[ii];
    while(tmp){
      i++;
      tmp = dir[ii];
      route = strcat(tmp,"/cmd");
      access(route,X_OK);
      if (!access(tmpB,X_OK)){
	puts(tmpB);
	return 1;
      }
    }printf("%s not found \n",cmd)
  }
    
  
    



int main(void){
  filldirs();
  return 0;
}
