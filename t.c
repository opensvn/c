#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a[32];
} A;

int main()
{
    char *p = (char *)malloc(0);
    char *q = p;

    p == NULL ? printf("NULL!\n") : printf("Not NULL!\n");
    *p = 'c';
    printf("%c\n", *p);

    free(p);

    printf("%c\n", *q);
    printf("A size: %ld\n", sizeof(A));

    return 0;
}
