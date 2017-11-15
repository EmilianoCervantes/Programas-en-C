#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void f1() {
	printf("Ya me voy\n");
}

int main(int argc, char const *argv[]) {
	//Cuando termine el programa
	atexit(f1);
	while(1){
		//x
	}

	//funciona con exit() o return()
	exit(0);
	//exit() es inmediato a diferencia de _exit()

	//return 0;
}