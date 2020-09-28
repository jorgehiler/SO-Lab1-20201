#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char buffer[300];
  FILE *fp;

  if(argc==1){
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }
  else if (argc==2){
    while(fgets(buffer, 300, stdin)){
      if(strstr(buffer, argv[1]) != NULL){
        printf("%s", buffer);
      }
    }
    return 0;
  }
  /*
  else if(strcmp(&argv[1]," ") == 0){
      exit(0);
  }
  */
  else if(argc > 2){
    for(int i=1; i< argc; i++){
      fp = fopen(argv[i+1],"r");
      char *line = NULL;
      size_t len = 0;

      if(fp == NULL) {
        printf("wgrep: cannot open file\n");
        return 1;
      }

      while (getline(&line, &len, fp)!= -1) {
        if(strstr(line, argv[i]) != NULL){
          printf ("%s", line);
        } 
      }
      i++;
      free(line);
      fclose(fp);
    }
  }

  return(0);
}