#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;
    struct flock lock;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Open error");
        exit(1);
    }

    printf("\nEnter StudentID to search : ");
    while (scanf("%d", &id) == 1) {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (id - 1001001) * sizeof(record);
        lock.l_len = sizeof(record);
        
        if (fcntl(fd, F_SETLKW, &lock) == -1) {
            perror("fcntl lock error");
            exit(1);
        }

        lseek(fd, (id - 1001001) * sizeof(record), SEEK_SET);
        if ((read(fd, (char *)&record, sizeof(record)) > 0) && (record.id != 0))
            printf("Name:%s \t StuID:%d \t Score:%d\n", record.name, record.id, record.score);
        else
            printf("No record %d\n", id);

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);

        printf("\nEnter StudentID to search : ");
    }

    close(fd);
    exit(0);
}
