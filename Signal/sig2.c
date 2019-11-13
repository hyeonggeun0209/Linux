#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig) {
    alarm_fired = 1;
}

int main() {

    pid_t pid;

    pid = fork();

    switch(pid) {
        case -1:
            break;
        case 0:
            sleep(5);
            kill(getppid(), SIGALRM);
            exit(0);
            break;
        default:
            break;
    }

    printf("waiting for alarm\n");
    (void) signal(SIGALRM, ding);

    pause();
    if (alarm_fired) printf("Ding!\n");

    return 0;
}