#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src, *dst;
    int c;

    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본> <복사본>\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    if (src == NULL) {
        perror("원본 파일 열기 실패");
        return 1;
    }

    dst = fopen(argv[2], "w");
    if (dst == NULL) {
        perror("복사본 파일 생성 실패");
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
