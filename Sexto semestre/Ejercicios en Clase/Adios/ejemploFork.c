#include <unistd.h>
#include <stdio.h>

int main(int argc, const char * argv[]){
	const char* c1;
	const char* c2;

	c1 = "Hola";

	pid_t pid;

	if(pid = fork()){
		c2 = "Mundo";
		sleep(1);
	}
	else{
		c1 = "Adios";
		c2 = "Proceso hijo";
	}
	printf("%s %s pid = %d\n", c1, c2, pid);
	return 0;
}