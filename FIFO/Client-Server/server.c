#include "common.h"

int main() {
    make_fifo(SERVER_FIFO_NAME);
    int server_fd = open_fifo(SERVER_FIFO_NAME, O_RDONLY);
    printf("Client connected\n");
    int client_fd = 0;
    
    char client_fifo[256];

    data_t buf;
    int read_bytes = 0;
    pid_t c_pid;
    char *ptr = 0;

    while(1) {
        read_bytes = read(server_fd, &buf, sizeof(buf));
        if (read_bytes <= 0) break;

        c_pid = buf.c_pid;
        ptr = buf.data;
        printf("Received data from process %d: %s\n", buf.c_pid, buf.data);
        while(*ptr != 0) {
            if (*ptr >= 65 && *ptr <= 90) *ptr += 32;
            else if (*ptr >= 97 && *ptr <= 122) *ptr -= 32;
            ptr++;
        }

        sprintf(client_fifo, CLIENT_FIFO_NAME, c_pid);
        client_fd = open(client_fifo, O_WRONLY);
        if (client_fd != -1) {
            write(client_fd, &buf, sizeof(buf));
            close(client_fd);
        }
    }

    close(server_fd);
    unlink(SERVER_FIFO_NAME);
    return 0;
}