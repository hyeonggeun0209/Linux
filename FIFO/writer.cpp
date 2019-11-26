//writer

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main() {

    mkfifo("fifo", 0777);
    int fd  = open("fifo", O_WRONLY | O_NONBLOCK);
    printf("wr open success\n");

    return 0;
}