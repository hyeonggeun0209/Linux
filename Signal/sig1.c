#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void sig_handler(int sig) {
   printf("123456\n");
   signal(SIGINT, SIG_DFL);
}

int main() {
    signal(SIGINT, sig_handler);
    while(1) {
        printf("HAHA\n");
        sleep(1);
    }

    return 0;
}