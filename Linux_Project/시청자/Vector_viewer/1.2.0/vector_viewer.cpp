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
			cout << "��ǥ�Ͻ� �������� �̸��� �Է����ּ���.";
			cin >> name;
			cout << "��ǥ �Ͻðڽ��ϱ�? [Y/N] ";
			cin >> yn;
			if (yn == "y" || yn == "Y") {
				viewers[num].vote(0, name);
				cout << "���������� ��ǥ�Ǿ����ϴ�." << endl << "��� ��ǥ �Ͻðڽ��ϱ�? [Y/N] ";
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
			cout << "��ǥ�Ͻ� �������� �̸��� �Է����ּ���.";
			cin >> name;
			cout << "��ǥ �Ͻðڽ��ϱ�? [Y/N].";
			cin >> yn;
			if (yn == "y" || yn == "Y") {
				viewers[num].vote(1, name);
				cout << "���������� ��ǥ�Ǿ����ϴ�." << endl;
				break;
			}
			else
				break;
		case 2:
			cout << "���̻� ��ǥ�ϽǼ� �����ϴ�." << endl;
			key = 0;
			break;
		default:
			break;
		}
	}
}

void vector_viewer::donation(vector<viewer> &viewers, int num) {
			int money;
			cout << "�Ŀ��Ͻ� �ݾ��� �Է����ּ���.";
			cin >> money;
			viewers[num].donate(money);
			cout << "���������� �Ŀ��Ǿ����ϴ�." << endl;
}

void vector_viewer::show(vector<viewer> &viewers, int num) {
		cout << "�޴��� ��ȣ : " << viewers[num].getNumber() << " ��ǥ�� �� : " << viewers[num].getVotePresence() << " ��ǥ�� ��� : " << viewers[num].getName() << " �Ŀ��� �ݾ� : " << viewers[num].getDonation() << endl;
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
