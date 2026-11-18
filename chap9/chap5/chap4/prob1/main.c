#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src;
    int c;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    if (src == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    while ((c = fgetc(src)) != EOF) {
        fputc(c, stdout);
    }

    fclose(src);
    return 0;
}
