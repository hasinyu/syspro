#include <stdio.h>

void file_cat(FILE *fp) {
    int c;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int i;

    if (argc < 2) {
        file_cat(stdin);
        return 0;
    }

    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "파일 열기 오류: %s\n", argv[i]);
            continue;
        }
        file_cat(fp);
        fclose(fp);
    }

    return 0;
}
