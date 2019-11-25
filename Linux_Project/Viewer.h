#include <string>
#include <iostream>
using namespace std;

class Viewer {
	string PhoneNumber; // 시청자의 휴대폰 번호 저장
	int VotePresence; // 시청자의 투표 여부 저장
	string VoteWho[2]; // 시정자가 투표한 후보 저장
	int donation; // 시청자가 후원한 금액 저장
public:
	Viewer(string PhoneNumber); // 생성되면서 인스턴스 변수 초기화
	void vote(string name1, string name2 = ""); // 최대 두명까지 가능한 투표 함수
	void donate(int money); // 출연자에게 후원 함수
};