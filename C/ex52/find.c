#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<assert.h>
#include <unistd.h>




int valid_name(const char * path){
  return (strcmp(path,".") && strcmp(path,".."));
}

int find_file(const char * path, const char * file_name){
/*  1.- open directory opendir
    2.- loop with readdir
        if valid_name
	currentname==filename? => print
	(lstat) and (s_isdir)directory? => recursive call
	     construct path
	        sprintf
    3.-" close directory  closedir*/
  DIR * list_dirs;
  struct dirent *one_file;
  struct stat st;
  int res = 0,status;
  char tmp[PATH_MAX + 1];
  list_dirs = opendir(path);
  assert(list_dirs!=NULL);
  while((one_file=readdir(list_dirs))!=NULL)
    if (valid_name(one_file->d_name)){
      if(!strcmp(one_file->d_name,file_name)){
	printf("%s/%s\n",path,file_name);
	res = 1;
      }
/* checking if we hqve a directory */
      snprintf(tmp,PATH_MAX + 1, "%s/%s",path,one_file->d_name);
      /* fprintf(stderr,"Accessing %s\n",tmp); */
      status=lstat(tmp,&st);
      if (status==-1)
	perror("lstat");
      assert(status!=-1);
      if(S_ISDIR(st.st_mode))
	res= (res || find_file(tmp,file_name)); /* logical or or equal */
    }
  closedir(list_dirs);
  return res;
}



int main( int argc, char *argv[] ){
  int res;
  res=find_file(".",argv[1]);
  return !res;
}
