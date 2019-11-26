#include "vector_viewer.h"
#include "viewer.h"

int main() {
	vector_viewer v;
	vector<viewer> a;
	int n, i, j = 1, k = 1;
	string num;
	while (k) {
		cout << "휴대폰 번호를 입력하세요.";
		cin >> num;
		i = v.check(a, num);
		if (i == -1) i = v.add(a, num);
		j = 1;
		while (j) {
			cout << "1:투표하기  2:후원하기  3:정보보기  4:로그아웃" << endl;
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