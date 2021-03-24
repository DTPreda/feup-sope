#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void message(){
  printf("Hello there!\n");
}

int main(void){
  printf("Hello World!\n");
  atexit(message);
  sleep(5); 
  return 0;
}

