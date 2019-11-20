#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

char c[40] = {0, };

void child(int pipe_pc[2], int pipe_cp[2]) {
    close(pipe_pc[1]);
    close(pipe_cp[0]);

    int n = 0;
    while(1) {
        read(pipe_pc[0], c, 40);

        printf("[C] received string: %s", c);

        n = strlen(c) - 1;
        write(pipe_cp[1], &n, sizeof(int));
        kill(getppid(), SIGUSR1); 
    }

}

void parent(pid_t c_pid, int pipe_pc[2], int pipe_cp[2]) {
    close(pipe_pc[0]);
    close(pipe_cp[1]);

    int n;
    while(1) {
        printf("[P] input string \n");
        fgets(c, 40, stdin);
   
        write(pipe_pc[1], c, 40);

        kill(c_pid, SIGUSR1);

        read(pipe_cp[0], &n, sizeof(int));
        printf("[P] length: %d\n", n);
       
    }
}

int main() {
    int pipe_pc[2]; int pipe_cp[2];
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