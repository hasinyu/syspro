#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본경로> <심볼릭링크명>\n", argv[0]);
        exit(1);
    }

    if (symlink(argv[1], argv[2]) < 0) {
        perror("symlink 오류");
        exit(1);
    }

    return 0;
}
