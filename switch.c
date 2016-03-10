#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        int n = rand() % 6 + 1;

        printf("---------------\n");
        switch (n)
        {
            case 1:
                if (rand() % 6 > 2)
                    printf("bigger\n");
                else
                    printf("smaller\n");
                break;
            case 2:
            case 3:
            case 4:
                if (rand() % 8 > 3)
                    printf(">3\n");
                else
                    printf("<=3\n");
                break;
            default:
                printf("default\n");
                break;
        }
        printf("---------------\n");
    }

    return 0;
}
