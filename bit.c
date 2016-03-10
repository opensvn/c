#include <stdio.h>

int count_bit(int n)
{
    int count = 0;

    while (n != 0)
    {
        ++count;
        n &= n - 1;
    }

    return count;
}

int main()
{
    for (int i = 0; i < 128; ++i)
    {
        printf("%d: bit->%d\n", i, count_bit(i));
    }

    return 0;
}
