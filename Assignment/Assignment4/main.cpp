#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include "hw_service.h"
#include <string>



using namespace std;

char msg[100];

void child(int pipe_pc[2], int pipe_cp[2]) {
    close(pipe_pc[1]);
    close(pipe_cp[0]);

    item_t item;
    int id, grade, n, a, avg;
    string name;
    start();
    unsigned int i = 0;

    read(pipe_pc[0], &n, sizeof(int));
    n = getNumStudents();
    write(pipe_cp[1], &n, sizeof(int));
    kill(getppid(), SIGUSR1);

    cout << "NumStudents : " << n << endl;

    for(i = 0; i < getNumStudents(); i++) {

        getItem(item);

        id = item.student_id;
        name = item.student_name;
        grade = item.grade;

        read(pipe_pc[0], &a, sizeof(int));
        write(pipe_cp[1], &grade, sizeof(int));
        kill(getppid(), SIGUSR1);

        cout << id << ' ';
        cout << name << ' ';
        cout << grade << ' ' << endl;
        
        deleteItem(id);
    }
    read(pipe_pc[0], &id, sizeof(int));
    write(pipe_cp[1], &a, sizeof(int));
    kill(getppid(), SIGUSR1);

    read(pipe_pc[0], &avg, sizeof(int));
    checkAnswer(id,avg,msg);
    write(pipe_cp[1], &msg, sizeof(msg));
}

void parent(pid_t c_pid, int pipe_pc[2], int pipe_cp[2]) {
    close(pipe_pc[0]);
    close(pipe_cp[1]);

    string name;
    int id, grade;
    int n, a;
    int total = 0;
    int avg;

    write(pipe_pc[1], &n, sizeof(int));
    kill(c_pid, SIGUSR1);

    read(pipe_cp[0], &n, sizeof(int));

    for(int i = 0; i < n; i++) {

        write(pipe_pc[1], &a, sizeof(int));
        kill(c_pid, SIGUSR1);

        read(pipe_cp[0], &grade, sizeof(int));
        total += grade;
        
    }

    avg = total / n;
    cout << "average : " << total / n << endl;

    cin >> id;

    write(pipe_pc[1], &id, sizeof(int));
    kill(c_pid, SIGUSR1);

    read(pipe_cp[0], &a, sizeof(int));
    write(pipe_pc[1], &avg, sizeof(int));
    kill(c_pid, SIGUSR1);

    read(pipe_cp[0], &msg, sizeof(msg));
    cout << msg << endl;

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