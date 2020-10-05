#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    
    if(argc == 1){
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    FILE *fp;
    int count = 1;
    int aux = 0;
    char character, oldChar;

    for(int i=1; i<argc; i++){
      
      fp = fopen(argv[i],"r");

      if(fp == NULL) {
        printf("wzip: cannot open file\n");
        return 1;
      }

      character = fgetc(fp);
      
      while(character != EOF){
        if(character == oldChar){
          count = count + 1;
        }
        else if(aux != 0){
          if(character != oldChar){
            fwrite(&count, 1, sizeof(count), stdout);
            fwrite(&oldChar, 1, 1, stdout);
            count =  1;
          }
        }
        aux = 1;
        oldChar = character;
        character = fgetc(fp);
      }
      fclose(fp);
    }
  fwrite(&count, 1, sizeof(count), stdout);
  fwrite(&oldChar, 1, 1, stdout);
  
  return(0);  
}