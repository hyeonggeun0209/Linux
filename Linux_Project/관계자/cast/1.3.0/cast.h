#pragma once
#include <string>
#include <iostream>

using namespace std;

class cast {
	string name;             // �⿬�� �̸�
	int age;             // �⿬�� ����
	string Entertainment;             // �⿬�� �Ҽӻ�
	int votes = 0;             // �⿬�� ��ǥ��
	int rank = -1;             // �⿬�� ����

public:
	void set(string name, int age, string Entertainment);             // �⿬�� ���� �Է��ϱ�
	void setname(string name);
	void setage(int age);
	void setEntertainment(string Entertainment);
	void addvote();
	int &getrank();
	int getvote();
	string getname();
	int getage();
	string getEntertainment();
};