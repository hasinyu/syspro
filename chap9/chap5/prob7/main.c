#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd, id;
    char c;
    struct student record;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        exit(1);
    }

    // 읽기와 쓰기가 모두 가능하도록 O_RDWR 모드로 파일 열기
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(1);
    }

    do {
        printf("수정할 학생의 학번 입력: ");
        if (scanf("%d", &id) == 1) {
            // 해당 학번의 레코드 위치로 오프셋 이동
            lseek(fd, (id - START_ID) * sizeof(struct student), SEEK_SET);
            
            // 해당 위치의 레코드 읽기
            if ((read(fd, (char *)&record, sizeof(struct student)) > 0) && (record.id != 0)) {
                printf("학번: %d \t 이름: %s \t 점수: %d\n", record.id, record.name, record.score);
                
                printf("새로운 점수 입력: ");
                scanf("%d", &record.score);
                
                // 수정을 위해 오프셋을 다시 해당 레코드의 시작 위치로 되돌림
                lseek(fd, (id - START_ID) * sizeof(struct student), SEEK_SET);
                
                // 수정된 레코드 쓰기
                write(fd, (char *)&record, sizeof(struct student));
            } else {
                printf("레코드 %d가 존재하지 않습니다.\n", id);
            }
        } else {
            printf("입력 오류\n");
        }

        printf("계속하겠습니까? (Y/N): ");
        scanf(" %c", &c);

    } while (c == 'Y' || c == 'y');

    close(fd);
    return 0;
}
