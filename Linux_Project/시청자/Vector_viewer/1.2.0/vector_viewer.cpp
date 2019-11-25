#include "vector_viewer.h"

int vector_viewer::add(vector<viewer> &viewers, string PhoneNumber) {
		viewer *p = new viewer;
		p->set(PhoneNumber, 0, 0);

		viewers.push_back(*p);
		return viewers.size() - 1;
}
void vector_viewer::vote(vector<viewer> &viewers, int num) {
	string name, yn;
	int key = 1;
	while (key) {
		int i = viewers[num].getVotePresence();
		switch (i) {
		case 0:
			cout << "투표하실 참가자의 이름을 입력해주세요.";
			cin >> name;
			cout << "투표 하시겠습니까? [Y/N] ";
			cin >> yn;
			if (yn == "y" || yn == "Y") {
				viewers[num].vote(0, name);
				cout << "정상적으로 투표되었습니다." << endl << "계속 투표 하시겠습니까? [Y/N] ";
				cin >> yn;
				if (yn == "y" || yn == "Y") {
					break;
				}
				else {
					key = 0;
					break;
				}
			}
			else
				break;
		case 1:
			cout << "투표하실 참가자의 이름을 입력해주세요.";
			cin >> name;
			cout << "투표 하시겠습니까? [Y/N].";
			cin >> yn;
			if (yn == "y" || yn == "Y") {
				viewers[num].vote(1, name);
				cout << "정상적으로 투표되었습니다." << endl;
				break;
			}
			else
				break;
		case 2:
			cout << "더이상 투표하실수 없습니다." << endl;
			key = 0;
			break;
		default:
			break;
		}
	}
}

void vector_viewer::donation(vector<viewer> &viewers, int num) {
			int money;
			cout << "후원하실 금액을 입력해주세요.";
			cin >> money;
			viewers[num].donate(money);
			cout << "정상적으로 후원되었습니다." << endl;
}

void vector_viewer::show(vector<viewer> &viewers, int num) {
		cout << "휴대폰 번호 : " << viewers[num].getNumber() << " 투표한 수 : " << viewers[num].getVotePresence() << " 투표한 사람 : " << viewers[num].getName() << " 후원한 금액 : " << viewers[num].getDonation() << endl;
}

int vector_viewer::check(vector<viewer> &viewers, string PhoneNumber) {
	int i = 0;
	for (i = 0; i < viewers.size(); i++) {
		if (viewers[i].getNumber() == PhoneNumber) {
			return i;
		}
	}
	if (i == viewers.size()) {
		return -1;
	}
}
