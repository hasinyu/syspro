#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {
    int fd;
    int n;
    long total = 0;
    char buf[BUFSIZE];

    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror(argv[1]);
        exit(1);
    }

    while ((n = read(fd, buf, BUFSIZE)) > 0) {
        total += n;
    }

    printf("%s File size : %ld Byte\n", argv[1], total);

    close(fd);
    return 0;
}
