#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    for (int i=0; i<len; ++i)
        printf("%.2x ", start[i]);
    printf("\n");
}

int main()
{
    int i = 12345;
    show_bytes((byte_pointer)&i, sizeof(int));
    return 0;
}
