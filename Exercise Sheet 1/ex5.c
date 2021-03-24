#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[], char* envp[]){
  if(argc != 0){
    for(int i = 0; i < argc; i++){
      printf("%s\n", argv[i]);
    }
  }
  printf("Environment Variables:\n");
  for(int i = 0; envp[i] != NULL; i++){
    printf("%s\n", envp[i]);
  }
  return 0;
}
