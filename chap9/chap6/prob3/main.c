#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    struct utimbuf timebuf;

    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본파일> <대상파일>\n", argv[0]);
        exit(1);
    }

    if (stat(argv[1], &buf) < 0) {
        perror("stat 오류");
        exit(1);
    }

    timebuf.actime = buf.st_atime;
    timebuf.modtime = buf.st_mtime;

    if (utime(argv[2], &timebuf) < 0) {
        perror("utime 오류");
        exit(1);
    }

    return 0;
}
