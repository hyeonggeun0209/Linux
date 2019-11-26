#include "cast.h"
#include "vector_cast.h"
#include "community.h"
#include "vector_viewer.h"
#include "viewer.h"
#include "my_star.h"


int main() {
	vector_cast ac;
	vector<cast> b;
	vector<string> c;
	community d;
	my_star Mystar;
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

				while (out2 != 1) {
					cout << "1 : Add cast 2 : Delete cast 3: Modify cast 4 : Show cast 5: vote 6: View Rank 7: End voting 8: View voting results 9: Community 10: Exit" << endl;
					cin >> key2;
					if (end_vote == 1 && (key2 != 6 && key2 != 8 && key2 != 9 && key2 != 10)) {
						cout << "Only show rank, show result, community, exit" << endl;
						continue;
					}
					else {
						switch (key2) {
						case 1:
							cout << "Please enter name, age, entertainment" << endl;
							cin >> name >> age >> en;
							ac.cast_add(b, name, age, en);
							break;
						case 2:
							cout << "Enter the name of the person you want to delete" << endl;
							cin >> name;
							ac.cast_delete(b, name);
							break;
						case 3:
							cout << "Enter the name of the person you want to modify" << endl;
							cin >> name;
							ac.cast_modify(b, name);
							break;
						case 4:
							ac.show(b);
							break;
						case 5:
							if (end_vote == 1) {
								cout << "end_vote!" << endl;
								break;
							}
							v.vote(a, b, i);
							ac.sort(b);
							break;
						case 6:
							v.show(b);
							break;
						case 7:
							ac.end_vote(b, end_vote);
							for (int q = 0; q < 3; q++) debut.push_back(b[q]);
							cout << " debut group " << endl;
							for (int q = 0; q < 3; q++) {
								cout << debut[q].getname() << " ";
							}
							cout << endl;

							break;
						case 8:
							if (end_vote == 0) {
								cout << "Voting is in progress." << endl;;
								break;
							}
							ac.show_vote(b);
							break;
						case 9:
							d.Community(c);
							break;
						case 10:
							out2 = 1;
							break;
						default:
							cout << "Wrong input!" << endl;
							break;
						}
					}
				}
			}
			else {
				cout << "Wrong" << endl;
				break;
			}
			break;
		case 2:
			cout << "Please enter your cell phone number.";
			cin >> num;
			i = v.check(a, num);
			out2 = 0;
			if (i == -1) i = v.add(a, num);
			while (out2 != 1) {
				out2 = 0;
				cout << "1: Voting  2: Sponsoring  3: See my Information 4: Show cast Information 5: View Rank 6: View voting results 7: Community 8 : To predict 9 : Predictive Results 10 : Exit" << endl;
				cin >> key2;
				switch (key2) {
				case 1:
					if (end_vote == 1) {
						cout << "end_vote!" << endl;
						break;
					}
					v.vote(a, b, i);
					ac.sort(b);
					break;
				case 2:
					if (end_vote == 1) {
						cout << "end_vote!" << endl;
						break;
					}
					v.donation(a, i);
					break;
				case 3:
					v.v_show(a, i);
					break;
				case 4:
					ac.show(b);
					break;
				case 5:
					v.show(b);
					break;
				case 6:
					if (end_vote == 0) {
						cout << "Voting is in progress. " << endl;
						break;
					}
					ac.show_vote(b);
					break;
				case 7:
					d.Community(c);
					break;
				case 8:
					if (end_vote == 1) {
						cout << "end_vote!" << endl;
						break;
					}
					v.addmy_star(a, b, i);
					break;
				case 9:
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
							cout << "You've made a good prediction!! " << endl <<
								"I'll call you at the number soon." << endl;
							break;
						}
					}else {
						cout << "You didn't make your debut group." << endl;
						break;
					}
					for (int i = 0; i < 3; i++) {

					}
					break;
				case 10:
					out2 = 1;
					break;
				default:
					cout << "wrong input!" << endl;
					break;
				}
			}
			break;
		case 3:
			out1 = 1;
			break;
		default:
			cout << "wrong input!" << endl;
			break;
		}
	}
}