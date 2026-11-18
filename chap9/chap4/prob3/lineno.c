#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int line = 1;

    if (argc < 2) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("파일 열기 실패");
            return 1;
        }
    }

    fprintf(stdout, "%3d: ", line++);
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
        if (c == '\n') {
            fprintf(stdout, "%3d: ", line++);
        }
    }

    if (fp != stdin) {
        fclose(fp);
    }
    return 0;
}
