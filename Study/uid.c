#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int uit_t = getuid();
	printf("%d\n",uit_t);
	return 0;
}
