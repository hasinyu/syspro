#include <stdio.h>
#include <string.h>
#include "copy.h"

int main() {
	char lines[5][MAXLINE];
	char temp[MAXLINE];

	for (int i = 0; i < 5; i++) {
		if (fgets(lines[i], MAXLINE, stdin) !=NULL) {
			size_t len = strlen(lines[i]);
			if (len > 0 && lines[i][len - 1] == '\n') {
				lines[i][len - 1] = '\0';
			}
		}
	}
	for (int i = 0; i <4; i++) {
		for (int j = 0; j < 4 - i; j++) {
			if (strlen(lines[j]) < strlen(lines[j + 1])) {
                copy(lines[j], temp);
                copy(lines[j + 1], lines[j]);
                copy(temp, lines[j + 1]);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}
