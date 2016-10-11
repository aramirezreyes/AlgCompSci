#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



/*  int execvp(const char* file, const char * argv[]); */



int main(int argc, char * argv[]){
  int fd;  
  assert(argc > 2);
  fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
  assert(fd != -1); /* it is better to us perror and those kinf of things */
  dup2(fd,STDOUT_FILENO);
  close(fd);
  execvp(argv[2], argv + 2);
  exit(EXIT_FAILURE); 
 }
