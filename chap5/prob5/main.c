#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd;
    struct student record;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        exit(1);
    }

    // 쓰기 전용, 생성, 기존 내용 삭제, 권한 0640으로 파일 열기
    if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0640)) == -1) {
        perror(argv[1]);
        exit(1);
    }

    printf("%-9s %-8s %s\n", "학번", "이름", "점수");

    // 콘솔에서 학번, 이름, 점수를 입력받아 레코드 파일에 저장
    while (scanf("%d %s %d", &record.id, record.name, &record.score) == 3) {
        // 학번을 기준으로 오프셋을 계산하여 해당 위치로 이동
        lseek(fd, (record.id - START_ID) * sizeof(struct student), SEEK_SET);
        write(fd, (char *)&record, sizeof(struct student));
    }

    close(fd);
    return 0;
}
