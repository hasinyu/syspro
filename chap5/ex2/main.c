#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int fd;
    char buf;
    char line[MAX_LINE];
    int idx = 0;
    int line_num = 1;

    if (argc != 3) {
        fprintf(stderr, "사용법: %s <검색단어> <파일명>\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[2], O_RDONLY)) == -1) {
        perror(argv[2]);
        exit(1);
    }

    // 파일에서 한 바이트씩 읽어 줄 단위로 분리한 뒤 검색어 포함 여부 확인
    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n' || idx >= MAX_LINE - 1) {
            line[idx] = '\0'; // 줄 완성
            
            // 지정한 검색어가 줄에 포함되어 있는지 확인
            if (strstr(line, argv[1]) != NULL) {
                printf("%d: %s\n", line_num, line);
            }
            
            idx = 0;
            line_num++;
        } else {
            line[idx++] = buf;
        }
    }

    // 마지막 줄에 개행 문자가 없는 경우 처리
    if (idx > 0) {
        line[idx] = '\0';
        if (strstr(line, argv[1]) != NULL) {
            printf("%d: %s\n", line_num, line);
        }
    }

    close(fd);
    return 0;
}
