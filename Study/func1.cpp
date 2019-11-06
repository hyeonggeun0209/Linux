 #include <iostream>
using namespace std;

void func1(int a, int b) {
	cout << a+b << endl;
}

void func2(int a, int b) {
	cout << a*b << endl;
}

int main() {
	void (*p)(int, int);

	p = func1;
	p(1,3);

	p = func2;
	p(2,5);

	return 0;
}
