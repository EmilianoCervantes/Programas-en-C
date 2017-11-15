#include <stdio.h>

int main(int argc, char **argv) {
  printf("%d\n", argc);
  int i;

  long unsigned int ptr = (long unsigned int) argv;
  for(i = 0; i < argc; i++) {
    printf("%lu\n", (long unsigned int)argv);
    printf("%s\n", *argv++);
    
  }
  printf("%s\n", *((char **)(ptr + 8)));
  

  return 0;
}