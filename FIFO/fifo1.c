#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int res = mkfifo("my_fifo", 0777);
    if (res == 0) printf("FIFO created!\n");
    else printf("Failed!\n");

    unlink("my_fifo");
    
    exit(EXIT_SUCCESS);
}