#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

    while(1){
        char* p = (char*) malloc(50 * 1024);
        if(p == NULL) break;
        // memset(p, 'A', 1); // Uncomment for the second variant of the exercise 
    }

    return 0;
}