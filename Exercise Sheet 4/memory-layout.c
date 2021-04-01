#include <stdio.h>
#include <stdlib.h>

int global = 10; // comment to verify size differences through size

int main(int argc, char* argv[]){
    int i = 10;

    char* heap = (char*) malloc(2 * sizeof(char));

    printf("In ascending order of memory:\n");
    printf("Address in text (main): %p\n", main); // functions that make up the code, such as main, are a part of text

    printf("Address in heap: %p\n", heap); // dynamically allocated variables are stored in the heap
    
    printf("Address in stack: %p\n", &i); // statically allocated variables are stored in the stack

    return i;
}