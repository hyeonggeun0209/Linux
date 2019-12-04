#include "common.h"

int main() {
    int server_fd = open_fifo(SERVER_FIFO_NAME, O_WRONLY);
    int client_fd = 0;

    data_t buf;
    buf.c_pid = getpid();
    memset(buf.data, 0, sizeof(buf.data));

    char client_fifo[256];
    sprintf(client_fifo, CLIENT_FIFO_NAME, buf.c_pid);
    make_fifo(client_fifo);

    int read_byte = 0;
    
    while(1) {
        printf("Input something (q:exit)\n");
        fgets(buf.data, BUF_SIZE, stdin);
        if (buf.data[0] == 'q' && buf.data[1] == 10) break;
        write(server_fd, &buf, sizeof(buf));
        client_fd = open(client_fifo, O_RDONLY);
        if (client_fd != -1) {
            read_byte = read(client_fd, &buf, sizeof(buf));
            if (read_byte > 0) {
                printf("received msg: %s\n", buf.data);
            }
            close(client_fd);
        }
    }

    close(server_fd);
    unlink(client_fifo);
}