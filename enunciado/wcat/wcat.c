#include <stdio.h>

int main(int argc, char *argv[]){
    char buffer[100];
    FILE *inFile;

    for(int i=1; i<argc; i++){
        inFile = fopen(argv[i],"r");
        if(inFile == NULL) {
            printf("wcat: cannot open file\n");
            return 1;
        }
        while(fgets(buffer, 100, inFile)!= NULL){
            printf("%s", buffer);
        }
        fclose(inFile);
    }

  return 0;
}

