#include "vector_viewer.h"
#include "viewer.h"

int main() {
	vector_viewer v;
	vector<viewer> a;
	int n, i, j = 1, k = 1;
	string num;
	while (k) {
		cout << "�޴��� ��ȣ�� �Է��ϼ���.";
		cin >> num;
		i = v.check(a, num);
		if (i == -1) i = v.add(a, num);
		j = 1;
		while (j) {
			cout << "1:��ǥ�ϱ�  2:�Ŀ��ϱ�  3:��������  4:�α׾ƿ�" << endl;
			cin >> n;
			switch (n) {
			case 1:
				v.vote(a, i);
				break;
			case 2:
				v.donation(a, i);
				break;
			case 3:
				v.show(a, i);
				break;
			case 4:
				j = 0;
				break;
			default:
				break;
			}
		}
	}
}