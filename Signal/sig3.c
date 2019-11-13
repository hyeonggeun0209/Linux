#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int num = 1;

void plus(int sig) {
    num = num + 1;
}
void child() { 
    for(int i = 2; i<=9; i+=2) {
        pause();
            for(int j = 1; j <= 9; j++) {
                printf("%d", num);
                printf("child : %d * %d = %d\n", i, j, i*j);
            }
        sleep(1);
        kill(getppid(), SIGUSR1); 
    }
}

void parent(pid_t pid) {
    if(num % 2 == 1) {
        for(int i = 1; i<=9; i+=2) {
            for(int j = 1; j <= 9; j++) {
                printf("%d", num);
                printf("parent : %d * %d = %d\n", i, j, i*j);
            }
            sleep(1);
            kill(pid, SIGUSR1);
            if(num == 5) exit(0);
            pause();
        }
    }
}

int main() {
    pid_t pid;

    pid = fork();

    signal(SIGUSR1, plus);

    switch(pid) {
        case 0:
            child();
            break;
        default:
            parent(pid);
            break;
    }
    return 0;
}