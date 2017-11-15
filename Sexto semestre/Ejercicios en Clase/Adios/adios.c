#include <unistd.h>
#include <stdio.h>

int main(){
	char * argv[2] = {"./hola", NULL};
	execvp("./hola", argv);
	printf("adios\n");
}