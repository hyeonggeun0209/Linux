#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class viewer {
	string PhoneNumber;   // ��û���� �޴��� ��ȣ ����
	int VotePresence;   // ��û���� ��ǥ ���� ����
	string VoteWho[2];   // �����ڰ� ��ǥ�� �ĺ� ����
	int donation;   // ��û�ڰ� �Ŀ��� �ݾ� ����
	vector<string> my_star;
public:
	void set(string PhoneNumber, int VotePresence, int donation);
	string getNumber();
	string getName();
	int getVotePresence();
	int getDonation();
	void vote(int num, string name);   // �ִ� �θ���� ������ ��ǥ �Լ�
	void donate(int money);   // �⿬�ڿ��� �Ŀ� �Լ�
	vector<string> & getmystar();
};