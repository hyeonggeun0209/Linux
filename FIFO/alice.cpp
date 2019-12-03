#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#define FIFO_NAME "my_fifo"
#define BUF_SIZE 1024

int main() {

    if (access(FIFO_NAME, F_OK) == -1) { // if no fifo_name then make fifo_name
        int res = mkfifo(FIFO_NAME, 0777);
        if (res != 0) {
            return -1;
        }
    }

    cout << "[Alice] Opening FIFO with O_WRONLY" << endl;
    int fd = open(FIFO_NAME, O_WRONLY);

    char buf[BUF_SIZE + 1];
    while (1) {
        cout << "[Alice] Input your msg" << endl;
        fgets(buf, BUF_SIZE, stdin);
        write(fd, buf, BUF_SIZE);
    }
}