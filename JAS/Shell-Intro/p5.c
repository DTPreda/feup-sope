#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    if(argc > 1){
        fprintf(stdout, "Hello %s\n", getenv(argv[1]));
    }
    else{
        fprintf(stdout, "Hello %s\n", getenv("USER"));
    }

    return 0;
}