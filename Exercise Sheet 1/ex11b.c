#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, "Wrong number of arguments.\n");
        return 1;
    }

    FILE* fp1; FILE* fp2;

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");

    if(fp1 == NULL){
        fprintf(stderr, "Unable to open file to be read.\n");
        return 1;
    }

    int c;
    while(1){
        c = fgetc(fp1);
        if(feof(fp1)) break;
        fprintf(fp2, "%c", c);
    }

    fclose(fp1); fclose(fp2);
    return 0;
}