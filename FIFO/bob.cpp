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

    cout << "[Bob] Opening FIFO with O_RDONLY" << endl;
    int fd = open(FIFO_NAME, O_RDONLY);

    char buf[BUF_SIZE + 1];
    int res = 0;
    while (1) {
        res = read(fd, buf, BUF_SIZE);
        if (res > 0) {
            cout << "[Bob] Received Msg: " << buf;
        } else {
            break;
        }
    }

    return 0;
}