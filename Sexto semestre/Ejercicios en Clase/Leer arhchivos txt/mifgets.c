#include <stdlib.h>
#include <stdio.h>

char* mifgets(char* ptr, int tamano, FILE* fptr){
	char* res = fgets(ptr, tamano, fptr);
	if (res == 0){
		return 0;
	}
	int i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n' && i < tamano)
		i++;
	if (i < tamano)
		ptr[i] = '\0';
	return res;	
}