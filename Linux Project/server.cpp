#include "common.h"
#include "vector_cast.h"
#include "vector_viewer.h"
#include "viewer.h"
#include <signal.h>

data_t buf;
int server_fd = 0;
int client_fd = 0;
char client_fifo[256];
pid_t c_pid, s_pid;
vector_cast ca;
vector<cast> c;
vector_viewer va;
vector<viewer> v;
string str(buf.data);
int id = 0;
string strage;
string all;
int money;

void sigusr1(int signo, siginfo_t *info, void *extra) { // client에서 sigqueue(server의 pid, SIGUSR1, int)을 보내면 
    int int_val = info->si_value.sival_int;				// signal handler에서 int값을 받아 switch문 실행
    int size;
    switch (int_val) {
        case 1:
            cout << "viewer vote" << endl;
            read(server_fd, &buf, sizeof(buf));
            str = buf.data;
            cout << str << endl;
            ca.vote(c, str);
            v[id].vote(v[id].getVotePresence(), str);
            break;
        case 2:
            break;
        case 4:
            cout << "viewer show" << endl;
            client_fd = open(client_fifo, O_WRONLY); // open client fifo (WRONLY)
            size = c.size();
            write(client_fd, &size, sizeof(int));
            for(int i = 0; i<size; i++) {
                strage = to_string(c[i].getage());
                all = c[i].getname() + ' ' + strage + ' ' + c[i].getEntertainment();
                strcpy(buf.data,all.c_str());
                write(client_fd, &buf, sizeof(buf));
            }
            close(client_fd); 
            break;
    }
}

void show(int sig) {
    int size = 0;
    string strage;
    string all;
    client_fd = open(client_fifo, O_WRONLY);
    size = c.size();
    write(client_fd, &size, sizeof(int));
    for(int i = 0; i<size; i++) {
        strage = to_string(c[i].getage());
        all = c[i].getname() + ' ' + strage + ' ' + c[i].getEntertainment();
        strcpy(buf.data,all.c_str());
        write(client_fd, &buf, sizeof(buf));
    }
    close(client_fd);
}

void vote(int sig) {
    read(server_fd, &buf, sizeof(buf));
    str = buf.data;
    cout << str << endl;
    ca.vote(c, str);
    v[id].vote(v[id].getVotePresence(), str);
    
}

void donate(int sig) {
    int key1;
    read(server_fd, &key1, sizeof(int));
    va.donation(v, id, key1);
    for(int i = 0, money = 0; i < v.size(); i++) {
        money+=v[i].getDonation();
    }
    string comment = "Thanks for your support";

    client_fd = open(client_fifo, O_WRONLY);
    strcpy(buf.data, comment.c_str());
    write(client_fd, &buf, sizeof(buf));
    close(client_fd);

}

void v_info(int sig) {
    string vall;
    string vpre;
    string vdon;
    client_fd = open(client_fifo, O_WRONLY); // open client fifo (WRONLY)
    vpre = to_string(v[id].getVotePresence());
    vdon = to_string(v[id].getDonation());
    vall = v[id].getNumber() + ' ' + vpre + ' ' + v[id].getName() + ' ' + vdon;
    client_fd = open(client_fifo, O_WRONLY);
    strcpy(buf.data,vall.c_str());
    write(client_fd, &buf, sizeof(buf));
    close(client_fd);

}

void show_rank(int sig) {
    ca.sort(c);
    int size = 0;
    string strage;
    string all;
    string vote;
    string rank;
    //cout << "viewer show" << endl;
    client_fd = open(client_fifo, O_WRONLY); // open client fifo (WRONLY)
    size = c.size();
    write(client_fd, &size, sizeof(int));
    for(int i = 0; i<size; i++) {
        strage = to_string(c[i].getage());
        vote = to_string(c[i].getvote());
        rank = to_string(c[i].getrank());
        all = c[i].getname() + ' ' + strage + ' ' + c[i].getEntertainment() + ' ' + vote + ' ' + rank;
        strcpy(buf.data,all.c_str());
        write(client_fd, &buf, sizeof(buf));
    }
    close(client_fd);
}

int main() {
    make_fifo(SERVER_FIFO_NAME);
    server_fd = open_fifo(SERVER_FIFO_NAME, O_RDONLY);
    cout << "Client connected" << endl;

    int read_bytes = 0;
    char *ptr = 0;
    string str(buf.data);
    string name;
    int age;
    string ent;
    int key, key1;
    int out = 1;
    int out1 = 1;
    int num;
    int size;
    string strage;
    string vall;
    string vpre;
    string vdon;

    struct sigaction action;			// 인터넷을 통해 얻은 코드

    action.sa_flags = SA_SIGINFO; 
    action.sa_sigaction = &sigusr1;
    sigaction(SIGUSR1, &action, NULL);*/
    if (sigaction(SIGUSR1, &action, NULL) == -1) { 
        perror("sigusr: sigaction");
        _exit(0);
     
    }

    signal(SIGUSR2, vote);
    signal(SIGUSR1, show);
    signal(SIGBUS, donate);
    signal(SIGILL, v_info);
    signal(SIGALRM, show_rank);
    read_bytes = read(server_fd, &buf, sizeof(buf));
    c_pid = buf.c_pid;
    str = buf.data;
    system("clear");
    cout << str << " client " << endl;

    id = va.check(v, str);
    if (id == -1) id = va.add(v, str);

    sprintf(client_fifo, CLIENT_FIFO_NAME, c_pid);
    client_fd = open(client_fifo, O_WRONLY); // open client fifo (WRONLY)
    buf.c_pid = getpid();
    if (client_fd != -1) {
        write(client_fd, &buf, sizeof(buf));
        close(client_fd);
    }

    while(out) {
        cout << endl<< "1 : Add cast 2 : Delete cast 3: Modify cast 4 : Show cast info " << endl << "6: View Rank 7: End voting 8: View voting results 9: Community 10: Exit" << endl;
        cin >> key;
        system("clear");
        switch (key) {
            case 1:
                cout << endl<< "Please enter name, age, entertainment" << endl;
                cin >> name >> age >> ent;
                ca.cast_add(c, name, age, ent);
                system("clear");
                break;
            case 2:
                cout << endl<< "Enter the name of the person you want to delete" << endl;
                cin >> name;
                ca.cast_delete(c,name);
                system("clear");
                break;
            case 3:
                cout << endl<< "Enter the name of the person you want to modify" << endl;
                cin >> name;
                ca.cast_modify(c, name);
                system("clear");
                break;
            case 4:
                system("clear");
                ca.show(c);
                break;
            case 6:
                ca.sort(c);
                ca.show(c);
                break;
            case 10:
                out = 0;
                break;
        }
    }
    close(server_fd);
    unlink(SERVER_FIFO_NAME);
    return 0;
}