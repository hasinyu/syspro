#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <8진수 권한> <파일이름>\n", argv[0]);
        exit(1);
    }

    int mode = strtol(argv[1], NULL, 8);

    if (chmod(argv[2], mode) < 0) {
        perror("chmod 오류");
        exit(1);
    }

    return 0;
}
