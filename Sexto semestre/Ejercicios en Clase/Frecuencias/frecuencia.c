#include <stdio.h>
#include <string.h>

typedef struct Palabra {
	char[20] palabra;
	int veces;
} Palabra;

void busca(Palabra palabras[], int *tamLogico, char* palabra) {
	for(int i = 0; i < *tamLogico; i++){
		if(strcmp(palabras[i]).palabra == 0){
			palabra[i].veces++;
			return;
		}
	}
	strcpy(palabras[*tamLogico].palabra, palabra);
	palabras[*tamLogico].veces = 1;
	(*tamLogico)++;
}

void escribir(Palabra palabras[], int tamLogico){
	for (int i = 0; i < tamLogico; ++i) {
		printf("%s %d\n", palabras[i].palabra, palabras[i].veces);
	}
}

int main() {
	Palabra palabras[100];
	char palabra[20];
	int tamaño;
	//EOF es igual a End Of File
	while(scanf("%s", palabra) !=EOF){
		//scanf("%s", palabra);
		busca(palabras, &tamaño, palabra);
	};
	escribir(palabras, tamaño);
	return 0;
}