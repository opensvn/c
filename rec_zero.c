#include <stdio.h>

typedef struct
{
    int nWorking;
    int nLng;
    int nLat;
    long long nLand;
} Record_NetLand;

int main()
{
    printf("size: %d\n", sizeof(Record_NetLand));

    Record_NetLand land = {0};

    for (int i = 0; i < sizeof(Record_NetLand); ++i)
    {
        printf("%d ", ((char *)(&land))[i]);
    }
    printf("\n");

    return 0;
}
