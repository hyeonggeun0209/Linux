#include <iostream>
#include <string>
#include <vector>
#include "viewer.h"

class vector_viewer {
	
public:
	int add(vector<viewer> &viewers, string PhoneNumber); // �޴��� ��ȣ�� ��û�� ���� �� ���� ����
	void vote(vector<viewer> &viewers, int num);
	void donation(vector<viewer> &viewers, int num);
	void show(vector<viewer> &viewers, int num);
	int check(vector<viewer> &viewers, string PhoneNumber);
};