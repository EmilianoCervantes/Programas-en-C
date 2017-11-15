#include <stdlib>
#include <stdio.h>

int main(){
	char archivo[] = "archivo.txt";
	FILE* fptr = fopen(archivo, "w");
	if(fptr == NULL){
		fprint(stderr, "Problemas al abrir el archivo\n");
		exit(1);
	}
	fprint(fptr, "Hola mundo sobre archivos\n");
	fprint(fptr, "Otra linea\n");
	fprint(stderr, "Esto va a la salida de error\n");
	fprint(stdout, "Esto va a la salida estándar\n");
	exit(1);
	fclose(fptr);
	return 0;
}