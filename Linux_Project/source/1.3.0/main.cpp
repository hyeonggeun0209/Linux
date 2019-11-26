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
	int n, i, k = 1;
	string num;
	int age;
	int end_vote = 0;
	string name;
	string en;

	int out1 = 0; // ��ü while
	int out2 = 0;// ��û��, ������ while
	int key1;
	int key2;
	while (out1 != 1) {
		out1 = 0;
		cout << "1: �����ڸ�� 2: ��û�ڸ�� 3: ������" << endl;
		cin >> key1;
		switch (key1) {
		case 1:
			cout << "����Է�" << endl;
			cin >> num;

			if (num == "1234") {
				i = v.check(a, num);
				if (i == -1) i = v.add(a, num);
				out2 = 0;

				while (out2 != 1) {
					cout << "1 : ��� �߰��ϱ� 2 : ��� �����ϱ� 3: ��� �����ϱ� 4 : �߰��� ����� ���� 5: ��ǥ�ϱ� 6: ���� ���� 7: ��ǥ ������ 8: ��ǥ��� ���� 9: �� ����. 10: ������" << endl;
					cin >> key2;
					if (end_vote == 1 && (key2 != 6 && key2 != 8 && key2 != 9 && key2 != 10)) {
						cout << "��ǥ��� ����� �� ���⸸ �����մϴ�." << endl;
						continue;
					}
					else {
						switch (key2) {
						case 1:
							cout << "�̸� ���� �Ҽӻ縦 ����" << endl;
							cin >> name >> age >> en;
							ac.cast_add(b, name, age, en);
							break;
						case 2:
							cout << "������ ����� �̸��� �����" << endl;
							cin >> name;
							ac.cast_delete(b, name);
							break;
						case 3:
							cout << "����� ��������" << endl;
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
							break;
						case 8:
							if (end_vote == 0) {
								cout << "���� ��ǥ�� ������ �Դϴ�." << endl;;
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
							cout << "wrong input!" << endl;
							break;
						}
					}
				}
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�" << endl;
				break;
			}
			break;
		case 2:
			cout << "�޴��� ��ȣ�� �Է��ϼ���.";
			cin >> num;
			i = v.check(a, num);
			out2 = 0;
			if (i == -1) i = v.add(a, num);
			while (out2 != 1) {
				out2 = 0;
				cout << "1:��ǥ�ϱ�  2:�Ŀ��ϱ�  3:�� ��ǥ���� 4: �⿬�� �������� 5: �������� 6: ��ǥ������� 7: �۾��� 8 : ������� 9 : �α׾ƿ�" << endl;
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
						cout << "���� ��ǥ�� ������ �Դϴ�. " << endl;
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