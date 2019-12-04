#include "common.h"
#include "stdlib.h"

void make_fifo(const char* file_name) {
    if (access(file_name, F_OK)== -1) {
        int res = mkfifo(file_name, 0777);
        if (res != 0) {
            exit(res);
        }
        printf("%s Creatd\n", file_name);
    }
}

int open_fifo(const char* file_name, int mode) {
    printf("Opening %s\n", file_name);
    return open(file_name, mode);
}