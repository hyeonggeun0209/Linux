#pragma once
#include <string>
#include <iostream>
using namespace std;

class viewer {
	string PhoneNumber; // ��û���� �޴��� ��ȣ ����
	int VotePresence; // ��û���� ��ǥ ���� ����
	string VoteWho[2]; // �����ڰ� ��ǥ�� �ĺ� ����
	int donation; // ��û�ڰ� �Ŀ��� �ݾ� ����
public:
	void set(string PhoneNumber, int VotePresence, int donation);
	string getNumber();
	string getName();
	int getVotePresence();
	int getDonation();
	void setNumber(string PhoneNumber); // ���ο� ��û�ڿ� ���� set�Լ�
	void setPresence(int num);
	void vote(int num, string name); // �ִ� �θ���� ������ ��ǥ �Լ�
	void donate(int money); // �⿬�ڿ��� �Ŀ� �Լ�
};