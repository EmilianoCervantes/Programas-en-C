#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int busca(char* palabras[], char* palabra, int inicio, int fin, char* quien) {
  int resultado = 0;
  for(int i = inicio; i < fin; i++) 
    if (strcmp(palabra, palabras[i]) == 0) {
      printf("encontrada %s\n", quien);
      resultado++;
    }
  return resultado;
}

int main(int argc, char* argv[]) {
  char * palabra = "hola";
  char* palabras[] = {"hola", "adios", "hola", "hola", "hola", "adios"};
  pid_t pid;
  if ((pid = fork())) {
    /* proceso padre */
    int res = busca(palabras, palabra, 0, 3, "padre");
    int status =0;
    waitpid(pid, &status, 0);
    waitpid(pid, &status, 0);
    status = WEXITSTATUS(status);
    printf("res padre = %d\n", res);
    printf("total = %d\n", res + status);
  }
  else {
    /* proceso hijo */
    int res = busca(palabras, palabra, 3, 6, "hijo");
    printf("res hijo = %d\n", res);
    exit(res);
  }
  return 0;
}