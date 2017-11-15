#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Alumno {
	char matricula[10];
	char nombre[51];
	char correo[19];
	int indice;
	int siguiente;
} Alumno;

typedef struct Nodo {
  struct Alumno alumno;
  struct nodo *siguiente;
} Nodo;

//inserta cada alumno en la lista ligada
void inserta(nodo* n, Alumno *alumno) {
	if (n->siguiente == NULL){
		n->siguiente = (nodo *) malloc(sizeof(nodo));
		n->siguiente->alumno = *alumno;
		n->siguiente->siguiente = NULL;
		n->alumno.siguiente = n->siguiente->alumno.indice;
	} else {
		inserta(n->siguiente, alumno);
	}
}

//Si desean agregar un nuevo alumno
Alumno nuevoAlumno(int indiceActual){
	Alumno a;
	printf("Matrícula: \n");
	scanf("%s", a.matricula);
	printf("Nombre: \n");
	scanf("%s", a.nombre);
	printf("Correo: \n");
	scanf("%s", a.correo);
	a.indice = indiceActual;
	return a;
}


//Para imprimir lo que se tiene en el archivo de salida
void impresion(Alumno a){
	printf("matricula: %s nombre: %s correo: %s, indice: %d\n", a.matricula, a.nombre, a.correo, a.indice);
}

//Lee el archivo de salida y va imprimiendo alumno por alumno
void impresion2(FILE* archivo, nodo* n){
	while(n != NULL)) {
		Alumno a = lee(archivo, i, n->alumno.indice);
		impresion(a);
		n = n->siguiente;
	}
}

//Lee el de entrada
Alumno lee(FILE* archivo, int reg, indice){
	long pos = 77 * reg;
	Alumno a;
	fseek(archivo, pos, SEEK_SET);
	fread(&(a.matricula), 9, 1, archivo);
	a.matricula[9] = '\0';
	fread(&(a.nombre), 50, 1, archivo);
	a.nombre[50] = '\0';
	fread(&(a.correo), 18, 1, archivo);
	a.correo[18] = '\0';
	a.indice = indice;
	return a;
}

int main() {
	//rb es lectura - binario
	FILE *alumno1 = fopen("estudiantes", "rb");
	FILE *alumno2 = fopen("estudiantes2","wb+");
	indice = -1;
	Alumno a = lee(alumno1, 0, indice);
	fseek(alumno1, 0, SEEK_END);
	int regs = ftell(alumno1) / 77;
	int indiceActual = -1;

	Nodo *raiz = NULL;
	raiz->siguiente = NULL;
	raiz.alumno = a;

	for (int i = 1; i < regs; i++) {
		indice++;
		Alumno otro = lee(alumno1, i, indice);
		inserta(&raiz, otro);
		indiceActual = 1;
	}

	acomoda(&raiz);
	fclose(alumno1);
	menu(&raiz, indiceActual);
	return 0;
}

//cada que se agrega algo se manda llamar
//Ordena a los alumnos
void acomoda(Nodo* raiz){
	Nodo *uno, *dos, *temp;
	uno = raiz;
	for(int i = 0; i < regs; i++) {
		if(uno.siguiente != NULL){
			dos = uno.siguiente;
			for (int j = i + 1; j < regs; j++) {
				if(dos.siguiente != NULL){
					if (strcmp(uno->alumno.nombre, dos->alumno.nombre) > 0) {
		                /*Con la lista ligada*/
		                temp = uno->alumno;
						uno->alumno = dos->alumno;
						dos->alumno = temp;
		            }
				}
				dos = dos.siguiente;
	        }
		}
		uno = uno.siguiente;
	}
}

//Imprime en el archivo de salida
void escribir(FILE* archivo, Nodo* n){
	//poner en el nuevo archivo la lista de alumnos con base en los nodos
	while(n != NULL){
		fprintf(archivo, "%s %d\n", n->alumno.nombre, n->alumno.edad);
		fprintf(archivo, "%s %s %s %d\n", n->alumno.matricula, n->alumno.nombre, n->alumno.correo, n->alumno.siguiente);
		n = n->siguiente;
	}
    fclose(f);
}

//Te manda las opciones del menú
int menu(Nodo* raiz, int indiceActual) {
	//FILE *alumno1 = fopen("estudiantes", "rb");
	FILE *alumno2 = fopen("estudiantes2","wb+");
	do {
		mostarMenu();
		int op = eleccion();
		realizarAccion(op, alumno2, &raiz, indiceActual);
	} while(op != 4);
}

void mostrarMenu() {	
	printf("\n");
	printf("¿Qué acción desea hacer? (Ingrese el número)\n");
	printf("1. Agregar\n");
	printf("2. Imprimir\n");
	printf("3. Borrar\n");
	printf("4. Salir\n");
	printf("\n");
}

int elegirOpcion() {
	int opcion;
	do {
		printf("Opción: \n");
		scanf("%d", &opcion);
		if(opcion < 1 | opcion > 4)
			printf("Opción inválida\n");
	} while(opcion < 1 | opcion > 5);
	return opcion;
	//Siempre que una función me regresa un valor, necesito el return
	//para saber qué valor me regresa
}

void realizarAccion(int opcion, FILE* archivo, Nodo* n, int indiceActual){
	switch(opcion) {
		case 1:
			printf("Dame los datos del nuevo alumno: \n");
			Alumno a = nuevoAlumno(indiceActual);
			inserta(&n, a);
			acomoda(&n);
			break;
		case 2:
			impresion2(archivo, &n);
			break;
		case 3:
			borrar(&n);
			break;
		case 4:
			printf("Hasta luego\n");
			break;
		default:
			break;
	}
}

//Borra lógicamente pero no físicamente
void borrar(Nodo* n){
	printf("Número del registro que desea borrar: \n");
	int indice;
	scanf("%d", &indice);
	Nodo temp;
	while(n != NULL){

		if(n->alumno.indice == indice){
			/*Anterior y siguiente se lo saltan*/
			temp->siguiente = n->siguiente;
		}
		temp = n;
		n = n-> siguiente;
	}
}