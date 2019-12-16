#include "common.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int server_fd = open_fifo(SERVER_FIFO_NAME, O_WRONLY);
    int client_fd = 0;

    data_t buf;
    buf.c_pid = getpid();

    pid_t s_pid;
    memset(buf.data, 0, sizeof(buf.data));

    char client_fifo[256];
    sprintf(client_fifo, CLIENT_FIFO_NAME, buf.c_pid);
    make_fifo(client_fifo);

    int read_bytes = 0;
    string name;
    int key, key1;
    int out = 1;
    int size;
    string num;
    string str(buf.data);

    cout << "Please enter your cell phone number." << endl; // client's phonenumber send!
    cin >> num;
    strcpy(buf.data, num.c_str()); // string to buf
    write(server_fd, &buf, sizeof(buf));

    client_fd = open(client_fifo, O_RDONLY); // server's pid get!
    if (client_fd != -1) {
        read_bytes = read(client_fd, &buf, sizeof(buf));
        s_pid = buf.c_pid;
        close(client_fd);
    }
    sigval s;
    system("clear");
    while(out) {
        cout << endl << "1: Voting  2: Sponsoring  3: See my Information 4: Show cast Information 5: View Rank 6 : quit" << endl;
        cin >> key;
        s.sival_int = key;
        sigqueue(s_pid, SIGUSR1, s);
        system("clear");
        switch (key) {
            case 1:
                system("clear");
                sigqueue(s_pid, SIGUSR1, s);
                break;
                //kill(s_pid, SIGUSR2);
                cout << "enter your pick" << endl;
                cin >> name;
                strcpy(buf.data, name.c_str());
                write(server_fd, &buf, sizeof(buf));
                break;
            case 2:
                system("clear");
                //kill(s_pid, SIGBUS);
                sigqueue(s_pid, SIGUSR1, s);
                break;
                cout << "enter donation you want" << endl;
                cin >> key1;
                write(server_fd, &key1, sizeof(int));
                client_fd = open(client_fifo, O_RDONLY);
                read(client_fd, &buf, sizeof(buf));
                str = buf.data;
                cout << str << endl;
                close(client_fd);
                break;
            case 3:
                system("clear");
                //kill(s_pid, SIGILL);
                sigqueue(s_pid, SIGUSR1, s);
                break;
                cout << "show my info" << endl;
                write(server_fd, &key, sizeof(int));
                client_fd = open(client_fifo, O_RDONLY);
                read(client_fd, &buf, sizeof(buf));
                str = buf.data;
                cout << "phonenum votenum votecast donation" << endl;
                cout << str << endl;     
                close(client_fd);
                break;
            case 4:
                system("clear");
                sigqueue(s_pid, SIGUSR1, s);
                //kill(s_pid, SIGUSR1);
                cout << "show all casts" << endl;
                client_fd = open(client_fifo, O_RDONLY);
                read(client_fd, &size, sizeof(int));
                cout << size << " casts "<< endl << endl;
                for(int i = 0; i < size; i++) {
                    read(client_fd, &buf, sizeof(buf));
                    str = buf.data;
                    cout << str << endl;
                }
                close(client_fd);
                break;
            case 5:
                system("clear");
                sigqueue(s_pid, SIGUSR1, s);
                break;
                //kill(s_pid, SIGALRM);
                cout << "show rank" << endl;
                client_fd = open(client_fifo, O_RDONLY);
                read(client_fd, &size, sizeof(int));
                cout << size << " casts "<< endl << endl;
                for(int i = 0; i < size; i++) {
                    read(client_fd, &buf, sizeof(buf));
                    str = buf.data;
                    cout << str << endl;
                }
                close(client_fd);
                break;
            case 6:
                out = 0;
                break;
        } 
    }     

    close(server_fd);
    unlink(client_fifo);

    return 0;
}