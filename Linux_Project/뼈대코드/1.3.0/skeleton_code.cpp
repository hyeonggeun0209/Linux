// 출연자 정보 저장 클래스

class cast {

	string name;         // 출연자 이름

	int age;         // 출연자 나이

	string Entertainment;         // 출연자 소속사

	int votes = 0;         // 출연자 득표수

	int rank = -1;         // 출연자 순위

public:

	void set(string name, int age, string Entertainment); // 출연자 정보 입력하기

	void modify(string name, int age, string Entertainment); // 출연자 정보 수정하기

	void setname(string name); // 출연자 이름 수정하기

	void setage(int age); // 출연자 나이 수정하기

	void setEntertainment(string Entertainment); // 출연자 소속사 수정하기

	string getname(); // 출연자 이름 얻어오기

	int getage(); // 출연자 나이 얻어오기

	string getEntertainment(); // 출연자 소속사 얻어오기
};


// 출연자 정보 저장 클래스를 관리할 관계자 클래스

class admin : public viewer {

	// 출연자들을 저장할 vector 선언

public:

	void cast_add(vector<cast> &casts, string name, int age, string Entertainment); // vector에 출연자 추가하기

	void cast_delete(vector<cast>& casts, string name); // vector에 출연자 삭제하기

	void cast_modify(vector<cast>& casts, string name); // vector에 있는 출연자 정보 수정하기

	void show(vector<cast> &casts);

};

// 시청자 클래스 및 도네이션 기능

class viewer {

	string PhoneNumber;         // 시청자의 휴대폰 번호 저장

	int VotePresence;         // 시청자의 투표 여부 저장

	string VoteWho[2];         // 시정자가 투표한 후보 저장

	int donation;         // 시청자가 후원한 금액 저장 (추가 기능)

public:

	void set(string PhoneNumber, int VotePresence, int donation); // 시청자 정보 입력하기

	string getNumber(); // 시청자의 휴대폰 번호 얻어오는 함수

	string getName(); // 시청자가 투표한 출연자를 얻어오는 함수

	int getVotePresence(); // 시청자의 투표 수를 얻어오는 함수

	int getDonation(); // 시청자의 후원 금액을 얻어오는 함수

	void vote(int num, string name); // 최대 두명까지 가능한 투표 함수

	void donate(int money);         // 출연자에게 후원 함수 (추가 기능)

};


// 시청자들의 정보를 저장할 클래스

class vector_viewer {

public:

	int add(vector<viewer> &viewers, string PhoneNumber); // 휴대폰 번호로 시청자 구분 후 벡터 저장

	void donation(vector<viewer> &viewers, int num);

	void show(vector<viewer> &viewers, int num);

	int check(vector<viewer> &viewers, string PhoneNumber);

};


// 투표 기능(필수)

class vote : public viewer {

public:
	void show_vote(string name); // 투표 결과 및 순위 공개 함수
};


// 투표 결과 및 순위 확인 기능

class show : public viewer {

public:

	void show_cast(string name); // 출연자의 정보 공개
};

// 게시판 기능 (추가 기능)

class community {

public:

	void Community(vector<string> &com);

};

// 3명의 데뷔조 예상 함수

class my_star {

	string names[3];

	string name;

	int j = 0;

	int out = 0;

	int key = 0;

	char keystr;

public:

	void My_star(vector<cast> casts, vector<string> &my_star);
}