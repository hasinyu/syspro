#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd;
    int id;
    struct student record;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }

    do {
        printf("\n검색할 학생 학번 입력 (-1 입력시 종료): ");
        if (scanf("%d", &id) == 1 && id == -1)
            break;

        // 입력받은 학번의 레코드 위치로 오프셋 이동
        lseek(fd, (id - START_ID) * sizeof(struct student), SEEK_SET);
        
        if ((read(fd, (char *)&record, sizeof(struct student)) > 0) && (record.id != 0)) {
            printf("학번: %d \t 이름: %s \t 점수: %d\n", record.id, record.name, record.score);
        } else {
            printf("레코드 %d가 존재하지 않습니다.\n", id);
        }

    } while (1);

    close(fd);
    return 0;
}
