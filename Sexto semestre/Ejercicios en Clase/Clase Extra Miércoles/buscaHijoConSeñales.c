#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int busca(char* palabras[], char* palabra, int inicio, int fin, char* quien){
	int resultado = 0;
	for (int i = inicio; i < fin; i++)
		if (strcmp(palabra, palabras[i]) == 0) {
			printf("Encontrada %s\n", quien);
			resultado++;
		}
	return resultado;
}

void busca_hijo(char* palabras[], char* palabra, int inicio, int fin, char* quien) {
  for(int i = inicio; i < fin; i++){
    if (strcmp(palabra, palabras[i]) == 0) {
      printf("encontrada %s\n", quien);
      kill(getppid(),SIGUSR1);
      sleep(1);
    }
  }
}

int total_hijo = 0;
void cuenta_hijo(int s){
  printf("señal del hijo\n");
  total_hijo++;
  signal(SIGUSR1,cuenta_hijo);
}

int main(int argc, char const *argv[]) {
	char * palabra = "hola";
	char* palabras[] = {"hola", "adios", "hola", "hola", "hola", "adios"};

	pid_t pid;

	if ((pid = fork())) {
		/* proceso padre */
		signal(SIGUSR1, cuenta_hijo);
		int res = busca(palabras, palabra, 0, 3, "padre");
		printf("resultado padre = %d\n", res);
		int status;
		waitpid(pid, &status, 0);
		printf("total = %d\n", res + total_hijo);
	} else {
		/* proceso hijo*/
		busca_hijo(palabras, palabra, 3, 6, "hijo");
	}
	return 0;
}