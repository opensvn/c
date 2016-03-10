#include <stdio.h>

long long call_num = 0;

int ack(int m, int n)
{
    ++call_num;

    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ack(m - 1, 1);
    else
        return ack(m - 1, ack(m, n - 1));
}

int main()
{
    printf("%d\n", ack(3, 3));
    printf("call number: %lld\n", call_num);
    return 0;
}
