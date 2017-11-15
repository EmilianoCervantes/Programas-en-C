#include <stdio.h>

int main(){
	int a, b;
	char* c = "12, 34";
	sscanf(c, "%d, %d", &a, &b);
	printf("Los números son: %d, %d\n", a, b);
	return 0;
}