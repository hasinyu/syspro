#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    printf("parental process start\n");

    // 첫 번째 자식: echo "hello"
    if ((pid1 = fork()) == 0) {
        execl("/bin/echo", "echo", "hello", NULL);
        fprintf(stderr, "execl echo failed\n");
        exit(1);
    }

    // 두 번째 자식: date
    if ((pid2 = fork()) == 0) {
        execl("/bin/date", "date", NULL);
        fprintf(stderr, "execl date failed\n");
        exit(1);
    }

    // 세 번째 자식: ls -l
    if ((pid3 = fork()) == 0) {
        execl("/bin/ls", "ls", "-l", NULL);
        fprintf(stderr, "execl ls failed\n");
        exit(1);
    }

    // 부모 프로세스가 자식들의 종료를 대기
    wait(&status);
    wait(&status);
    wait(&status);

    printf("parental process end\n");
    return 0;
}
