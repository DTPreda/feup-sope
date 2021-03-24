#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, "Wrong number of arguments.\n");
        return 1;
    }
    char command[100];

    sprintf(command, "cat %s > %s", argv[1], argv[2]);
    system(command);

    return 0;
}