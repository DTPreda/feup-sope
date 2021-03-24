#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if(argc == 2){
    if(open(argv[1]) == -1){
      perror("Error: ");
    }
  }
  else perror("Invalid number of arguments: ");
  return 0;
}
