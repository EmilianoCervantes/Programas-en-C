#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int busca(char* palabras[], char* palabra, int) {
	int resultado = 0;
	for (int i = 0; i < fin; ++i) {
		if (strcmp)
		{
			printf("Encontrada %s\n", quien);
			resultado ++;
		}
	}
	return resultado;
}

int main(int argc, char const *argv[])
{
	char* palabra = "hola";
	char* palabras[] = {"hola", "adios", "hola", "hola"};
	t_pid pid;
	//asignación, no comparación
	if (pid = fork())
	{
		/* proceso padre */
		int resultado = busca(palabras, "hola", 0, 2, "padre");
		int status;
		waitpaid(pid, &status, 0);
		waitpaid(pid, &status, 0);
		WEXITSTATUS(status);
		printf("resultado = %d\n", status);
	} else {
		/* proceso hijo */
		int resultado = busca(palabras, "hola", 2, 4, "hijo");
		printf("resultado = %d\n", resultado);
		exit(resultado);
	}
	return 0;
}