#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    for(int i = 0; i < 100000; i++){
        printf("Hello World!\n");
    }
    system("time ls -R /tmp");
    return 0;
}