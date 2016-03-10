#include <stdio.h>

static union 
{ 
    char c[4]; 
    unsigned long l; 
} endian_test = {'l', '?', '?', 'b'};

#define ENDIANNESS ((char)endian_test.l)

int main()
{
    if (ENDIANNESS == 'l')
        printf("Little endian\n");
    else
        printf("Big endian\n");

    return 0;
}
