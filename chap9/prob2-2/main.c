#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;
    int status;

    printf("[%d] parental process start\n", (int)getpid());

    // 첫 번째 자식 프로세스 생성
    pid1 = fork();
    if (pid1 < 0) {
        fprintf(stderr, "Fork 1 failed\n");
        return 1;
    } else if (pid1 == 0) {
        printf("[%d] child process[1] start\n", (int)getpid());
        sleep(1);
        printf("[%d] child process[1] end\n", (int)getpid());
        exit(1);
    }

    // 두 번째 자식 프로세스 생성
    pid2 = fork();
    if (pid2 < 0) {
        fprintf(stderr, "Fork 2 failed\n");
        return 1;
    } else if (pid2 == 0) {
        printf("[%d] child process[2] start\n", (int)getpid());
        sleep(2);
        printf("[%d] child process[2] end\n", (int)getpid());
        exit(2);
    }

    // 부모 프로세스: 첫 번째 자식 프로세스의 종료를 기다림
    pid_t child_pid = wait(&status);
    printf("[%d] child process[1] %d end\n", (int)getpid(), (int)child_pid);
    
    if (WIFEXITED(status)) {
        printf("      end code %d\n", WEXITSTATUS(status));
    }

    return 0;
}
