#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>


/*  int execvp(const char* file, const char * argv[]); */



int main(int argc, char * argv[]){
  assert(argc > 1);
  pid_t pid;
  int status;
  pid = fork();
  switch(pid){
  case -1: /* error */
    perror("Process creation");
    exit(EXIT_FAILURE);
  case 0:
    execvp(argv[1],argv+1); /* The first one is a string and the second is a table of strings */
    perror("Mutation"); /* we throw an error bc if the child runs after the execvp st is not working */
    exit(EXIT_FAILURE); 
  default:; /* this is what the father does */
  }
  pid = wait(&status);
  assert(pid!=-1);

  if(WIFEXITED(status))
    return WEXITSTATUS(status);
  fprintf(stderr, "Child failed? \n");
  exit(EXIT_FAILURE);
}
