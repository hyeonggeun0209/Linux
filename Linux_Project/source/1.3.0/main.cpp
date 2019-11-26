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

	int out1 = 0; // 전체 while
	int out2 = 0;// 시청자, 관계자 while
	int key1;
	int key2;
	while (out1 != 1) {
		out1 = 0;
		cout << "1: 관계자모드 2: 시청자모드 3: 나가기" << endl;
		cin >> key1;
		switch (key1) {
		case 1:
			cout << "비번입력" << endl;
			cin >> num;

			if (num == "1234") {
				i = v.check(a, num);
				if (i == -1) i = v.add(a, num);
				out2 = 0;

				while (out2 != 1) {
					cout << "1 : 사람 추가하기 2 : 사람 삭제하기 3: 사람 수정하기 4 : 추가된 사람들 보기 5: 투표하기 6: 순위 보기 7: 투표 끝내기 8: 투표결과 보기 9: 글 쓰기. 10: 나가기" << endl;
					cin >> key2;
					if (end_vote == 1 && (key2 != 6 && key2 != 8 && key2 != 9 && key2 != 10)) {
						cout << "투표결과 보기와 글 쓰기만 가능합니다." << endl;
						continue;
					}
					else {
						switch (key2) {
						case 1:
							cout << "이름 나이 소속사를 적어" << endl;
							cin >> name >> age >> en;
							ac.cast_add(b, name, age, en);
							break;
						case 2:
							cout << "삭제할 사람의 이름을 적어봐" << endl;
							cin >> name;
							ac.cast_delete(b, name);
							break;
						case 3:
							cout << "사람을 수정하자" << endl;
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
								cout << "아직 투표가 진행중 입니다." << endl;;
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
				cout << "틀렸습니다" << endl;
				break;
			}
			break;
		case 2:
			cout << "휴대폰 번호를 입력하세요.";
			cin >> num;
			i = v.check(a, num);
			out2 = 0;
			if (i == -1) i = v.add(a, num);
			while (out2 != 1) {
				out2 = 0;
				cout << "1:투표하기  2:후원하기  3:내 투표보기 4: 출연자 정보보기 5: 순위보기 6: 투표결과보기 7: 글쓰기 8 : 사람고르기 9 : 로그아웃" << endl;
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
						cout << "아직 투표가 진행중 입니다. " << endl;
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