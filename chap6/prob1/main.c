#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    struct stat buf;

    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일 경로들>\n", argv[0]);
        exit(1);
    }

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        
        if (lstat(argv[i], &buf) < 0) {
            perror("lstat()");
            continue;
        }

        if (S_ISREG(buf.st_mode))
            printf("Regular File\n");
        else if (S_ISDIR(buf.st_mode))
            printf("Directory\n");
        else if (S_ISCHR(buf.st_mode))
            printf("Character Device\n");
        else if (S_ISBLK(buf.st_mode))
            printf("Block Device\n");
        else if (S_ISFIFO(buf.st_mode))
            printf("FIFO\n");
        else if (S_ISLNK(buf.st_mode))
            printf("Symbolic Link\n");
        else if (S_ISSOCK(buf.st_mode))
            printf("Socket\n");
        else
            printf("Unknown\n");
    }

    return 0;
}
