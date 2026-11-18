#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
int main() {
    pid_t pid;

    // 자식 프로세스 생성
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스: 새로운 프로세스 그룹 리더가 됨
        setpgid(0, 0);
        printf("Child Process - PID: %d, PGID: %d\n", (int)getpid(), (int)getpgrp());
        sleep(5);
    } else {
        // 부모 프로세스
        printf("Parent Process - PID: %d, Child PID: %d, PGID: %d\n", 
               (int)getpid(), (int)pid, (int)getpgrp());
        wait(NULL);
    }

    return 0;
}
