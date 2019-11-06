#include <iostream>
#include <time.h>
using namespace std;

int main() {
	const time_t t = time(NULL);
	struct tm *cur = localtime(&t);

	cout << cur->tm_hour << ":" << cur->tm_min << ":" << cur->tm_sec << endl;

	return 0;
}
