#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void child(int pipe_pc[2], int pipe_cp[2]) {
    close(pipe_pc[1]);
    close(pipe_cp[0]);

    int n;
    printf("[C] waiting for user input ... \n");
    read(pipe_pc[0], &n, sizeof(int));
    printf("[C] received number: %d \n", n);

    n *= n;
    write(pipe_cp[1], &n, sizeof(int));
    kill(getppid(), SIGUSR1);

}

void parent(pid_t c_pid, int pipe_pc[2], int pipe_cp[2]) {
    close(pipe_pc[0]);
    close(pipe_cp[1]);

    int n;
    printf("[P] input number \n");
    scanf("%d", &n);
    write(pipe_pc[1], &n, sizeof(int));

    kill(c_pid, SIGUSR1);

    read(pipe_cp[0], &n, sizeof(int));
    printf("[P] square: %d\n", n);
}

int main() {
    int pipe_pc[2], pipe_cp[2];
    pipe(pipe_pc);
    pipe(pipe_cp);

    signal(SIGUSR1, SIG_IGN);
    pid_t pid = fork();

    switch(pid) {
        case 0:
            child(pipe_pc, pipe_cp);
            break;
        default:
            parent(pid, pipe_pc, pipe_cp);
            break;
    }

    return 0;
}