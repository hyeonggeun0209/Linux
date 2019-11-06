#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main() {
    time_t *t = malloc(sizeof(time_t));
    struct tm *ct;

    *t = time(NULL);
    ct = localtime(t);

    printf("%d-%d-%d %d:%d:%d\n", ct->tm_year+1900,ct->tm_mon,ct->tm_mday,ct->tm_hour,ct->tm_min,ct->tm_sec);

    return 0;
}