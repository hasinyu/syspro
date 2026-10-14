#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본파일> <링크파일>\n", argv[0]);
        exit(1);
    }

    if (link(argv[1], argv[2]) < 0) {
        perror("link 오류");
        exit(1);
    }

    return 0;
}
