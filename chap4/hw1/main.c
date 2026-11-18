#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src, *dst;
    int c;

    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본> <추가할대상>\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    if (src == NULL) {
        perror("원본 파일 열기 실패");
        return 1;
    }

    dst = fopen(argv[2], "a");
    if (dst == NULL) {
        perror("대상 파일 열기 실패");
        fclose(src);
        return 1;
    }

    while ((c = fgetc(src)) != EOF) {
        fputc(c, dst);
    }

    fclose(src);
    fclose(dst);
    return 0;
}
