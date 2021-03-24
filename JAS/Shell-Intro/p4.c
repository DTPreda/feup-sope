#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 3){
        fprintf(stderr, "Invalid number of arguments\n");
        return -1;
    }

    for(int i = 1; i < argc - 1; i++){
        if(atoi(argv[i])){
            fprintf(stdout, "One or more invalid arguments\n");
            return -1;
        }
    }

    if(atoi(argv[argc - 1]) <= 0){
        fprintf(stdout, "Invalid last argument\n");
        return -1;
    }

    for(int i = 0; i < atoi(argv[argc - 1]); i++){
        fprintf(stdout, "Hello ");
        for(int j = 1; j < argc - 1; j++){
            fprintf(stdout, " %s", argv[j]);
        }
        fprintf(stdout, "\n");
    }
    
    return 0;
}