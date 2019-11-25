// �⿬�� ���� ���� Ŭ����

class cast {

	string name;         // �⿬�� �̸�

	int age;         // �⿬�� ����

	string Entertainment;         // �⿬�� �Ҽӻ�

	int votes;         // �⿬�� ��ǥ��

	int rank;         // �⿬�� ����



public:

	void set(string name, int age, string Entertainment);         // �⿬�� ���� �Է��ϱ�

	void modify(string name, int age, string Entertainment);         // �⿬�� ���� �����ϱ�

};



// �⿬�� ���� ���� Ŭ������ ������ ������

class vector_cast {

	vector<cast> casts;         // �⿬�ڵ��� ������ vector ����

	string name;         // �⿬�� �̸�

	int age;         //�⿬�� ����

	string Entertainment;         // �⿬�� �Ҽӻ�

public:

	void cast_add(vector<casts> cast, string name, int age, string Entertainment);         // vector�� �⿬�� �߰��ϱ�

	void cast_delete(vector<casts> cast, string name);         // vector�� �⿬�� �����ϱ�

	void cast_modify(vector<casts> cast, string name, int age, string Entertainment);         // vector�� �ִ� �⿬�� ���� �����ϱ�

};



// ��û�� Ŭ���� �� �����̼� ���

class Viewer {

	string PhoneNumber;         // ��û���� �޴��� ��ȣ ����

	int VotePresence;         // ��û���� ��ǥ ���� ����

	string VoteWho[2];         // �����ڰ� ��ǥ�� �ĺ� ����

	int donation;         // ��û�ڰ� �Ŀ��� �ݾ� ���� (�߰� ���)

public:

	void set(string PhoneNumber);         // �����Ǹ鼭 �ν��Ͻ� ���� �ʱ�ȭ

	void vote(string name1, string name2 = "");         // �ִ� �θ���� ������ ��ǥ �Լ�

	void donate(int money);         // �⿬�ڿ��� �Ŀ� �Լ� (�߰� ���)

};



// ��û�ڵ��� ������ ������ Ŭ����

class vector_viewer {

	vector<Viewer> viewers;

public:

	void viewer_add(string PhoneNumber);  // �޴��� ��ȣ�� ��û�� ���� �� ���� ����

};



// ��ǥ ��� �� ���� Ȯ�� ���

void show_vote(string name1 = "", string name2 = ""); // ��ǥ ��� �� ���� ���� �Լ�, �Ű������� �ƹ��͵� �� �ָ� ��� �⿬���� ��ǥ ��� �� ���� ����



// ��ǥ ���(�ʼ�)

void show_cast(string name1 = "", string name2 = ""); // �⿬���� ���� ���� �Լ�, �Ű������� �ƹ��͵� �� �ָ� ��� �⿬���� ���� ����



// �Խ��� ��� (�߰� ���)

class community {

	static string *textArray;

	static int num;         // �Խ��ǿ� �ö� �� ��

public:

	static void add(string text);         // �Խ��ǿ� �� �߰��ϱ�

	static void print();         // �Խ��ǿ� ������ �� ����ϱ�

};



//���� ���� ���(�߰� ���)

void guess_debut(string name1, string name2, string name3); // 3���� ������ ���� �Լ�