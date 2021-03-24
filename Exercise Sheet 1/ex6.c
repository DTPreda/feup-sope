#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
  if (argc == 2){
    if (open(argv[1]) == -1){
     fprintf(stderr, "Falhaste tanso\n");
    }
  }
  else fprintf(stderr, "More than 1 arg\n");
  return 0;
}
