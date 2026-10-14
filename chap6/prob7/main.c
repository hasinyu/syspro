#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s <삭제할 링크파일>\n", argv[0]);
        exit(1);
    }

    if (unlink(argv[1]) < 0) {
        perror("unlink 오류");
        exit(1);
    }

    return 0;
}
