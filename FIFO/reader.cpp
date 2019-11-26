// reader

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("fifo", O_RDONLY);
    printf("rd open success\n");


    return 0;
}