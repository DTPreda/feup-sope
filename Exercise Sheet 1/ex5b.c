#include <stdlib.h>
#include <stdio.h>

int check(char* st1, char* st2){
  int last = 0;
  for(int i = 0; st1[i] != '\0'; i++){
    if(st1[i] != st2[i]){
      return 1;
    }
    last = i;
  }
  if(st2[last + 1] != '=') return 1;
  return 0;
}

int main(int argc, char* argv[], char* envp[]){
  for(int i = 0; envp[i] != NULL; i++){
    for(int j = 0; j < argc; j++){
      if(check(argv[j], envp[i]) == 0){
        printf("%s\n", envp[i]);
      }
    }
  }
  return 0;
}
