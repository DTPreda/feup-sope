#include <stdlib.h>
#include <stdio.h>

int main(void){

    int pid = fork();

    if(pid != 0){
        waitpid(0);
        fprintf(stdout, "World!\n");
    } else {
        fprintf(stdout, "Hello ");
    }

    return 0;
}