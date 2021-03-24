#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    if(argc > 3 || argc <= 1){
        fprintf(stderr, "Wrong number of arguments.\n");
        return 1;
    }

    int file1 = open(argv[1], O_RDONLY);
    if(file1 == -1){
        fprintf(stderr, "First file could not be opened.\n");
        return 1;
    }

    char data[1000];
    int bytes = 0;
    if((bytes = read(file1, data, 1000)) < 0){
        fprintf(stderr, "Could not read first file.\n");
        return 1;
    }

    if(argc == 2){
        if(write(0, data, bytes) < 0){
            fprintf(stderr, "Could not write to second file.\n");
            return 1;
        }
    }
    else{
        int file2 = open(argv[2], O_TRUNC | O_WRONLY);  
        if(file2 == -1){
            fprintf(stderr, "Second file could not be opened.\n");
            return 1;
        }
        if(write(file2, data, bytes) < 0){
            fprintf(stderr, "Could not write to second file.\n");
            return 1;
        }
    }

    return 0;
}