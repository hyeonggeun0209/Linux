#include <iostream>
#include <string>
#include <vector>
#include "Viewer.h"

class vector_viewer {
	vector<Viewer> viewers;
public:
	void viewer_add(string PhoneNumber); // 휴대폰 번호로 시청자 구분 후 벡터 저장
};