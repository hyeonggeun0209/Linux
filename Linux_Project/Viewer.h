#include <string>
#include <iostream>
using namespace std;

class Viewer {
	string PhoneNumber; // ��û���� �޴��� ��ȣ ����
	int VotePresence; // ��û���� ��ǥ ���� ����
	string VoteWho[2]; // �����ڰ� ��ǥ�� �ĺ� ����
	int donation; // ��û�ڰ� �Ŀ��� �ݾ� ����
public:
	Viewer(string PhoneNumber); // �����Ǹ鼭 �ν��Ͻ� ���� �ʱ�ȭ
	void vote(string name1, string name2 = ""); // �ִ� �θ���� ������ ��ǥ �Լ�
	void donate(int money); // �⿬�ڿ��� �Ŀ� �Լ�
};