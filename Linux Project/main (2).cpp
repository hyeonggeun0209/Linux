
#include "cast.h"
#include "vector_cast.h"
#include "community.h"
#include "vector_viewer.h"
#include "viewer.h"

int main() {
        vector_cast ac;
        vector<cast> b;
        vector<string> c;
        community d;
        vector<string> inmystar;
        vector_viewer v;
        vector<viewer> a;
        vector<cast> debut;
        int n, i, k = 1;
        string num;
        int age;
        int end_vote = 0;
        string name;
        string en;
        int m;
        int out1 = 0;
        int out2 = 0;
        int key1;
        int key2; 
        int money =0;
        int predic=0;
        while (out1 != 1) {
                out1 = 0;
                cout << "1: Admin mode 2: Viewer mode 3: Exit" << endl;
                cin >> key1;
                switch (key1) {
                case 1:
                        cout << "Enter password" << endl;
                        cin >> num;

                        if (num == "1234") {
                                i = v.check(a, num);
                                if (i == -1) i = v.add(a, num);
                                out2 = 0;
                                system("clear");
                                while (out2 != 1) {
                                        cout << endl<< "1 : Add cast 2 : Delete cast 3: Modify cast 4 : Show cast 5: vote " << endl << "6: View Rank 7: End voting 8: View voting results 9: Community 10: Exit" << endl;
                                        cin >> key2;
                                        if (end_vote == 1 && (key2 != 6 && key2 != 8 && key2 != 9 && key2 != 10)) {
                                                cout << endl<< "Only show rank, show result, community, exit" << endl;
                                                continue;
                                        }
                                        else {
                                                switch (key2) {
                                                case 1:
                                                        cout << endl<< "Please enter name, age, entertainment" << endl;
                                                        cin >> name >> age >> en;
                                                        ac.cast_add(b, name, age, en);
                                                        break;
                                                case 2:
                                                        cout << endl<< "Enter the name of the person you want to delete" << endl;
                                                        cin >> name;
                                                        ac.cast_delete(b, name);
                                                        break;
                                                case 3:
                                                        cout << endl<< "Enter the name of the person you want to modify" << endl;
                                                        cin >> name;
                                                        ac.cast_modify(b, name);
                                                        break;
                                                case 4:
                                                        ac.show(b);
                                                        break;
                                                case 5:
                                                        if (end_vote == 1) {
                                                                cout << endl<< "end_vote!" << endl;
                                                                break;
                                                        }
                                                        if(b.size() == 0 ){
                                                                cout << endl << "You can't vote yet";
                                                                cout << endl;
                                                                break;
                                                        }
                                                        v.vote(a, b, i);
                                                        ac.sort(b);
                                                        break;
                                                case 6:
                                                        v.show(b);
                                                        break;
                                                case 7:
                                                        if(b.size() < 3){
                                                                cout << endl << "Could not end voting" << endl;
                                                                break;
                                                        }
                                                        ac.end_vote(b, end_vote);
                                                        for (int q = 0; q < 3; q++) debut.push_back(b[q]);
                                                        cout << endl<< "debut group ";
                                                        cout << endl;
                                                        for (int q = 0; q < 3; q++) {
                                                                cout << debut[q].getname() << " ";
                                                        }
                                                        cout << endl;

                                                        break;
                                                case 8:
                                                        if (end_vote == 0) {
                                                                cout << endl<< "Voting is in progress." << endl;;
                                                                break;
                                                        }
                                                        ac.show_vote(b);
                                                        cout << endl;
                                                        break;
                                                case 9:
                                                        d.Community(c);
                                                        cout << endl;
                                                        break;
                                                case 10:
                                                        out2 = 1;
                                                        cout << endl;
                                                        break;
                                                default:
                                                        cout << endl<< "Wrong input!" << endl;
                                                        break;
                                                }
                                        }
                                }
                        }
                        else {
                                cout <<endl<< "Wrong" << endl;
                                break;
                        }
                        break;
                case 2:
                        cout << endl<< "Please enter your cell phone number.";
                        cin >> num;
                        i = v.check(a, num);
                        out2 = 0;
                        if (i == -1) i = v.add(a, num);
                        system("clear");
                        while (out2 != 1) {
                                out2 = 0;
                                
                                cout << endl << "1: Voting  2: Sponsoring  3: See my Information 4: Show cast Information 5: View Rank " << endl << "6: View voting results 7: Community 8 : To predict 9 : Predictive Results 10 : Exit" << endl << "You can make predictions when you sponsor more than 5000." << endl << " And if you're successful, you'll get the total funding. (10% commission)" << endl;
                                cin >> key2;
                                switch (key2) {
                                case 1:
                                        if (end_vote == 1) {
                                                cout << endl<< "end_vote!" << endl;
                                                break;
                                        }
                                        if(b.size() == 0 ){
                                                cout << endl << "You can't vote yet";
                                                cout << endl;
                                                break;
                                        }
                                        v.vote(a, b, i);
                                        ac.sort(b);
                                        cout << endl;
                                        break;
                                case 2:
                                        if (end_vote == 1) {
                                                cout << endl<< "end_vote!" << endl;
                                                break;
                                        }
                                        v.donation(a, i);
                                        for(int i=0, money = 0; i< a.size() ;i++){
                                                money+=a[i].getDonation();
                                        }
                                        cout << endl;
                                        break;
                                case 3:
                                        v.v_show(a, i);
                                        cout << endl;
                                        break;
                                case 4:
                                        ac.show(b);
                                        cout << endl;
                                        break;
                                case 5:
                                        v.show(b);
                                        cout << endl;
                                        break;
                                case 6:
                                        if (end_vote == 0) {
                                                cout << endl<< "Voting is in progress. ";
                                                cout << endl;
                                                break;
                                        }
                                        ac.show_vote(b);
                                        cout << endl;
                                        break;
                                case 7:
                                        d.Community(c);
                                        break;
                                case 8:
                                        if (end_vote == 1) {
                                                cout << endl<< "end_vote!" << endl;
                                                break;
                                        }
                                        v.addmy_star(a, b, i);
                                        break;
                                case 9:
                                        if(end_vote == 0){
                                                cout << endl<< "Voting is in progress. ";
                                                cout << endl;
                                                break;
                                        }
                                        m = 0;
                                        if (a[i].getmystar().size() == 3) {
                                                for (int p = 0; p < 3; p++) {
                                                        for (int j = 0; j < 3; j++) {
                                                                if (a[i].getmystar()[p] == debut[j].getname()) {
                                                                        m++;
                                                                }
                                                        }
                                                }
                                                if (m == 3) {
                                                        if(a[i].getpre() == 0){
                                                                 a[i].getpre()++; 
                                                        }
                                                        
                                                        for(int c = 0, predic =0 ; c < a.size(); c++){
                                                                predic += a[c].getpre();
                                                        }
                                                        if(predic == 0){
                                                                predic =1;
                                                        }
                                                        cout << endl<< "You've made a good prediction!! " << " I'll call you at the number soon.";
                                                        cout << endl;
                                                        break;
                                                }else if(m == 2 || m == 1 || m ==0){
                                                        cout << endl<< "you predicted " << m <<" that's too bad,,,," << endl;
                                                }
                                                
                                        }else {
                                                cout << endl<< "You didn't make your debut group." << endl;
                                                break;
                                        }
                                        cout << endl;
                                        break;
                                case 10:
                                        out2 = 1;
                                        cout << endl;
                                        break;
                                default:
                                        cout << endl<< "wrong input!" << endl;
                                        break;
                                }
                        }
                        
                        break;
                case 3:
                        out1 = 1;
                        break;
                default:
                        cout << endl<< "wrong input!" << endl;
                        break;
                }
        }
}
