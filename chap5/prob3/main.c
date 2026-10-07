#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {
    int fd1, fd2;
    int n;
    char buf[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본파일> <복사할파일>\n", argv[0]);
        exit(1);
    }

    if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }

    if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1) {
        perror(argv[2]);
        exit(1);
    }

    while ((n = read(fd1, buf, BUFSIZE)) > 0) {
        write(fd2, buf, n);
    }

    close(fd1);
    close(fd2);
    return 0;
}
