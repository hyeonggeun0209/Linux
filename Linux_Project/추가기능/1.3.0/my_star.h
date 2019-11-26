#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cast.h";
using namespace std;
class my_star {
	string names[3];
	string name;
	int j = 0;
	int out = 0;
	int key = 0;
	char keystr;
public:
	void My_star(vector<cast> casts, vector<string> &my_star);
	// 3명의 데뷔조 예상 함수
};