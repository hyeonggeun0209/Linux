// 출연자 정보 저장 클래스

class cast {

	string name;         // 출연자 이름

	int age;         // 출연자 나이

	string Entertainment;         // 출연자 소속사

	int votes;         // 출연자 득표수

	int rank;         // 출연자 순위



public:

	void set(string name, int age, string Entertainment);         // 출연자 정보 입력하기

	void modify(string name, int age, string Entertainment);         // 출연자 정보 수정하기

};



// 출연자 정보 저장 클래스를 저장할 큻래스

class vector_cast {

	vector<cast> casts;         // 출연자들을 저장할 vector 선언

	string name;         // 출연자 이름

	int age;         //출연자 나이

	string Entertainment;         // 출연자 소속사

public:

	void cast_add(vector<casts> cast, string name, int age, string Entertainment);         // vector에 출연자 추가하기

	void cast_delete(vector<casts> cast, string name);         // vector에 출연자 삭제하기

	void cast_modify(vector<casts> cast, string name, int age, string Entertainment);         // vector에 있는 출연자 정보 수정하기

};



// 시청자 클래스 및 도네이션 기능

class Viewer {

	string PhoneNumber;         // 시청자의 휴대폰 번호 저장

	int VotePresence;         // 시청자의 투표 여부 저장

	string VoteWho[2];         // 시정자가 투표한 후보 저장

	int donation;         // 시청자가 후원한 금액 저장 (추가 기능)

public:

	void set(string PhoneNumber);         // 생성되면서 인스턴스 변수 초기화

	void vote(string name1, string name2 = "");         // 최대 두명까지 가능한 투표 함수

	void donate(int money);         // 출연자에게 후원 함수 (추가 기능)

};



// 시청자들의 정보를 저장할 클래스

class vector_viewer {

	vector<Viewer> viewers;

public:

	void viewer_add(string PhoneNumber);  // 휴대폰 번호로 시청자 구분 후 벡터 저장

};



// 투표 결과 및 순위 확인 기능

void show_vote(string name1 = "", string name2 = ""); // 투표 결과 및 순위 공개 함수, 매개변수로 아무것도 안 주면 모든 출연자의 투표 결과 및 순위 공개



// 투표 기능(필수)

void show_cast(string name1 = "", string name2 = ""); // 출연자의 정보 공개 함수, 매개변수로 아무것도 안 주면 모든 출연자의 정보 공개



// 게시판 기능 (추가 기능)

class community {

	static string *textArray;

	static int num;         // 게시판에 올라간 글 수

public:

	static void add(string text);         // 게시판에 글 추가하기

	static void print();         // 게시판에 쓰여진 글 출력하기

};



//데뷔 추측 기능(추가 기능)

void guess_debut(string name1, string name2, string name3); // 3명의 데뷔조 예상 함수