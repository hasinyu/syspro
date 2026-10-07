#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int fd;
    int n;
    char buf;
    long chars = 0, words = 0, lines = 0;
    int in_word = 0;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }

    while ((n = read(fd, &buf, 1)) > 0) {
        chars++;
        if (buf == '\n') {
            lines++;
        }
        if (isspace(buf)) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            words++;
        }
    }

    close(fd);

    printf("줄 수(Lines): %ld\n", lines);
    printf("단어 수(Words): %ld\n", words);
    printf("문자 수(Chars): %ld\n", chars);

    return 0;
}
