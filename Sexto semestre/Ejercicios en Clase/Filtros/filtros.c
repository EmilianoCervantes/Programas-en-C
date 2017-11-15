#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	int p[2];
	//Pipe crea un arreglo de dos elemntos
	//Posición 0 es entrada
	//Posición 1 es salida
	pipe(p);
	if (fork() ==0) {
		close(p[1]);
		//duplica la entrada
		dup2(p[0], 0);
		//Comando 'cat' lee desde la entrada estandar, escribe sobre la salida estándar
		//Especie de eco
		//execlp("bin/cat", "cat", "-", NULL); //PARA LINUX
		//execlp("cat", "cat", "-", NULL);
		execlp("ls", "ls", "*", NULL);
		//Ctrl-C para terminar
		printf("Error al momento de ejecutar cat\n");
	}
	close(p[0]);
	while(1)
		write(p[1], ".", 1);
	return 0;
}