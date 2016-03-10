#include <stdio.h>
#include <time.h>
#include <unistd.h>

int new_year(time_t time_)
{
    time_t now = time(NULL);

    struct tm tm1 = *localtime(&time_);
    struct tm tm2 = *localtime(&now);

    if (tm1.tm_year == tm2.tm_year)
    {
        printf("not new year\n");
    }
    else
    {
        printf("new year\n");
    }

    return tm1.tm_year == tm2.tm_year;
}

time_t DayStart(time_t nTime)
{
    struct tm *tblock;

    tblock = localtime(&nTime);

    tblock->tm_hour = 0;
    tblock->tm_min = 0;
    tblock->tm_sec = 0;

    nTime = mktime(tblock);

    return nTime;
}

time_t DayStart_r(time_t nTime)
{
    struct tm tblock;

    localtime_r(&nTime, &tblock);

    tblock.tm_hour = 0;
    tblock.tm_min = 0;
    tblock.tm_sec = 0;

    nTime = mktime(&tblock);

    return nTime;
}

void display_tm(struct tm *t)
{
    printf("second: %d\n", t->tm_sec);
    printf("min: %d\n", t->tm_min);
    printf("hour: %d\n", t->tm_hour);
    printf("mday: %d\n", t->tm_mday);
    printf("mon: %d\n", t->tm_mon);
    printf("year: %d\n", t->tm_year);
    printf("wday: %d\n", t->tm_wday);
    printf("yday: %d\n", t->tm_yday);
    printf("isdst: %d\n", t->tm_isdst);
}

int main()
{
    // time_t t = time(NULL) - (2 << 12);
    // new_year(t);
    // printf("tm1\n");
    // time_t t1 = time(NULL);
    // struct tm tm1 = *localtime(&t1);

    // display_tm(&tm1);

    // sleep(3);

    // printf("\ntm2\n");
    // time_t t2 = time(NULL);
    // struct tm tm2 = *localtime(&t2);

    // display_tm(&tm2);

    time_t day_start = DayStart_r(time(NULL));
    display_tm(localtime(&day_start));

    return 0;
}