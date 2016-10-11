#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<assert.h>
#include <unistd.h>

/* System call ----> error test maybe perror */


int valid_name(const char * path){
  return (strcmp(path,".") && strcmp(path,".."));
}

int what_is_it(const char *path){
    struct stat st;
    int res=0;
    lstat(path, &st);
    if(S_ISREG(st.st_mode))
      res = 1;
    if(S_ISDIR(st.st_mode))
      res = 2;
    if(S_ISLNK(st.st_mode))
      res = 3;
    return res;
}

void explore_directory(char *path){
  DIR * list_dirs;
  struct dirent *one_file;
  list_dirs = opendir(path);
  assert(list_dirs!=NULL);
  while((one_file=readdir(list_dirs))!=NULL)
    if (valid_name(one_file->d_name)){
      printf("%s\n",one_file->d_name);
    }
  closedir(list_dirs);
}

void follow_link(char *path){
  char tmp[PATH_MAX + 1];
  ssize_t len;
  len = readlink(path,tmp,sizeof(tmp)-1);
  if (len!=-1){
    tmp[len] =  '\0';
    printf("%s --> %s\n",path, tmp);
  }
}

int main(int argc, char *argv[]){
  char *path;
  path = argv[1];
  switch(what_is_it(path)){
  case 1:
    printf("The path provided (%s) is a regular file \n",path);
    break;
  case 2:{
    printf("The path given is a directory with contents: \n");
    explore_directory(path);
    break;
    }
  case 3:{
    printf("The path given is a link related ponting to:  \n");
     follow_link(path);
     break;
  }
}



  return 0;
}
