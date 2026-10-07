#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;

    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("파일 열기 오류");
    } else {
        printf("파일 '%s' 열기 성공! 파일 디스크립터 = %d\n", argv[1], fd);
    }

    close(fd);
    return 0;
}
