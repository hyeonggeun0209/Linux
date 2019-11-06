#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	char c;
	int in;
	int count = 0;

	in = open("input.txt", O_RDONLY);

	while (read(in, &c, 1)==1) {
		count++;	
	}

	close(in);
	printf("%d\n",count);

	return 0;
}
