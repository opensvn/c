#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void print_arr(int *a, int len)
{
    printf("[");
    for (int i = 0; i < len; ++i)
    {
        if (i != len - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
    printf("]\n");
}

void cat_arr(int *a, int len)
{
    int b[len];
    memset(b, 0, sizeof(b));

    int last_value = 0;
    int can_add = 0;

    for (int i = 0, j = 0; i < len; ++i)
    {
        if (a[i] != 0)
        {
            if (a[i] == last_value)
            {
                if (can_add)
                {
                    b[j-1] += a[i];
                    can_add = 0;
                }
                else
                {
                    b[j++] = a[i];
                    can_add = 1;
                }
            }
            else if (a[i] != last_value)
            {
                b[j++] = a[i];
                last_value = a[i];
                can_add = 1;
            }
        }
    }

    for (int i = 0; i < len; ++i)
    {
        a[i] = b[i];
    }
}

int main()
{
    int a[16] = {0};

    srand(time(NULL));

    int c[] = {0, 2, 4, 8};

    for (int i = 0; i < 16; ++i)
    {
        a[i] = c[rand() % 4];
    }
    
    print_arr(a, sizeof(a) / sizeof(int));

    cat_arr(a, sizeof(a) / sizeof(int));

    print_arr(a, sizeof(a) / sizeof(int));

    return 0;
}