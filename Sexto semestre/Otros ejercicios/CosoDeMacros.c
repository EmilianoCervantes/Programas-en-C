#include <stdio.h>
#define MAX(a,b) ((a) > (b))? (a) : (b)
#define MIN(a,b) ((a) < (b))? (a) : (b)

//int fp(int a, int b) {return a+b; }
//int fm(int a, int b) {return a*b; }
#define APPLY(a,b,o) f##o(a,b)
#define RUN(a,b,c,d,o) APPLY(a,APPLY(b,APPLY(c,d,o),o),o)

int main(void)
{
    /*int a = 0;
    int b = 1;
    int c = MAX(a++,b++);
    printf("a = %d, b = %d, max = %d",a,b,c);

    printf("%d %d\n", RUN(1,2,3,4,p), RUN(1,2,3,4,m));
    */
    int cosa;

    printf("%i\n", cosa);
    return 0;
}
