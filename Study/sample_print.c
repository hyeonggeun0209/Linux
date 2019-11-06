#include <stdio.h>

int main() {
	const char *name = "Welcome to Linux Programming\n";
	char buf[100];
	FILE *out = fopen("out", "w");

	printf("printf result: %s", name);
	sprintf(buf, "sprintf result: %s", name);
	printf("%s", buf);
	
	fprintf(out, "fprintf result: %s", name);
	
	return 0;
}
