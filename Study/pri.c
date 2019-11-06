#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	char c[2];
	int out;
 
	out = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	while (1) {
		read(0, c, 2);
		if (c[0] == 'q')
			break;
		write(out, c, 1);
	}

	close(out);
	
	return 0;
}
