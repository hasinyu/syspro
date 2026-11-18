#include <stdio.h>

int main() {
    FILE *fp;
    int id;
    char name[20];
    int score;

    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    printf("--- 학생 정보 목록 ---\n");
    while (fscanf(fp, "%d %s %d", &id, name, &score) == 3) {
        printf("학번: %d, 이름: %s, 성적: %d\n", id, name, score);
    }

    fclose(fp);
    return 0;
}
