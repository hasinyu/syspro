#include <stdio.h>

struct Student {
    int id;
    char name[20];
    int score;
};

int main() {
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        printf("구조체 데이터 읽기 -> 학번: %d, 이름: %s, 성적: %d\n", s.id, s.name, s.score);
    }

    fclose(fp);
    return 0;
}
