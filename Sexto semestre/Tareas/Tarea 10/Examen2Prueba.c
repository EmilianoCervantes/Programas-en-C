#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>

int main(int argc, char const *argv[]) {

    FILE *archivo1;
    FILE *archivo2;
    char archivoU[] = "Texto1.txt";
    char archivoD[] = "Texto2.txt";

    archivo1 = fopen(archivoU, "r");
    if(archivo1 == NULL){
        fprintf(stderr, "Error");
    }
    archivo2 = fopen(archivoD, "r");
    if(archivo2 == NULL){
        fprintf(stderr, "Error");
    }

	char linea[100];
	if(fork()=0){
        while (fgets(linea,100,archivo1) != NULL) {
            Map(Dividir(linea), 1);
        }
	} else {
        while (fgets(linea,100,archivo2) != NULL) {
            Map(Dividir(linea), 1);
        }
	}

	fclose(archivo1);
	fclose(archivo2);
	return 0;
}
///Regresa array de palabras
char* Dividir(char* linea){

    char palabras[20][10];
    ///
    return palabras;
}
///asignar las llaves a cada palabra
void Map(char* palabras, int llave){

}
///Reducir mapa
void Reducir(){
}
