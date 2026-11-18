#include <stdio.h>

struct Student {
    int id;
    char name[20];
    int score;
};

int main() {
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "wb");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    printf("학번 이름 성적 입력 (예: 20261234 김철수 95):\n");
    if (scanf("%d %s %d", &s.id, s.name, &s.score) == 3) {
        fwrite(&s, sizeof(struct Student), 1, fp);
    }

    fclose(fp);
    return 0;
}
