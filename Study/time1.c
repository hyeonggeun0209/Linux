#include <sys/time.h>
#include <stdio.h>

struct timeval tv;

void tic() {
    gettimeofday(&tv, NULL);
}

long toc() {
    struct timeval tv2;
    gettimeofday(&tv2, NULL);
    return (tv2.tv_sec*1000000 + tv2.tv_usec) - (tv.tv_sec*1000000 + tv.tv_usec);
}

int main() {
    tic();
    for(int i=0;i<1000;i++){
        printf("hi\n");
    }
    printf("%d\n",(int)toc());
    return 0;
}