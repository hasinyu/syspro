#include <stdio.h>

int main() {
    FILE *fp;
    int id;
    char name[20];
    int score;

    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    printf("학번 이름 성적을 입력하세요 (종료: Ctrl+D):\n");
    while (scanf("%d %s %d", &id, name, &score) == 3) {
        fprintf(fp, "%d %s %d\n", id, name, score);
    }

    fclose(fp);
    return 0;
}
