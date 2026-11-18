#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int main() {
	char line[MAXLINE];

	printf("Input lines:\n");
	while(fgets(line, MAXLINE, stdin) != NULL) {
		printf("%s", line);
	}

	return 0;
}
