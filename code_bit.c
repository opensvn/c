#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned long long gate: 6;
    unsigned long long code: 12;
    unsigned long long number: 46;
} record_code;

int main()
{
    printf("%lu\n", sizeof(record_code));
    printf("%lu\n", sizeof(unsigned long long));

    int a[0];
    printf("%lu\n", sizeof(a));
    memset(a, 0, sizeof(a));
    return 0;
}
