#include <stdlib.h>
#include <stdio.h>

int main(void){
    atexit(fprintf(stdout, "Executing exit handle 1"));
    atexit(fprintf(stdout, "Executing exit handle 2"));

    fprintf(stdout, "Main done!");
    return 0;
}