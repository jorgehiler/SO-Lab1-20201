#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){    
  FILE *fp;


  if(argc == 1){
    printf("wunzip: file1 [file2 ...]\n");
    return 1;
  }

  for(int i=1; i<argc; i++){
    fp = fopen(argv[i],"r");
    int rep;
    char character;

    if(fp == NULL) {
      printf("wzip: cannot open file\n");
      return 1;
    }

    while(fread(&rep, 4, 1, fp)){;
      fread(&character, 1, 1, fp);
      for(int j = 0; j<rep; j++){
        printf("%c", character);
      }
    }
    fclose(fp);
  }

  return 0;
    
}