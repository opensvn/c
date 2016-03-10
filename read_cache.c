#include <stdio.h>
#include <string.h>

typedef struct
{
    long long nCode;
    int nLng;
    int nLat;
    char nType:4;
    char nSub:4;
    char nGender:2;
    char nRe:6;
    char nRe2[2];
    int nFreq;
} Record_Thing;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "arguments not fit!\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    //FILE *fp = fopen("test.dat", "r");

    int num = 0;
    int cnt = 0;
    fread(&num, sizeof(int), 1, fp);
    printf("num: %d\n", num);

    Record_Thing thing;
    while (!feof(fp) && cnt < num)
    {
        fread(&thing, sizeof(Record_Thing), 1, fp);
        printf("%lld, %d, %d, %d\n", thing.nCode, thing.nLng,
                thing.nLat, thing.nFreq);
        ++cnt;
    }

    fclose(fp);
/*
    fp = fopen("test.dat", "wb");
    memset(&thing, 0, sizeof(Record_Thing));
    thing.nCode = 12345;
    fwrite(&thing, sizeof(Record_Thing), 1, fp);
    fclose(fp);*/

    return 0;
}
