#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b))? (a) : (b)
#define MIN(a,b) ((a) < (b))? (a) : (b)
int main(void) {
    int a = 0;
    int b = 1;
    int c = MAX(a++,b++);
    printf("a = %d, b = %d, max = %d",a,b,c);
    return 0;
}
