#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cast.h"

using namespace std;

class vector_cast {
	// �⿬�ڵ��� ������ vector ����
	// �⿬�� �Ҽӻ�

public:
	void cast_add(vector<cast> &casts, string name, int age, string Entertainment);             // vector�� �⿬�� �߰��ϱ�
	void cast_delete(vector<cast>& casts, string name);             // vector�� �⿬�� �����ϱ�

	void cast_modify(vector<cast>& casts, string name);             // vector�� �ִ� �⿬�� ���� �����ϱ�
	void show(vector<cast> &casts);
	void end_vote(vector<cast> casts, int &end_vote);
	void show_vote(vector<cast> &casts);
	void sort(vector<cast> &casts);

};