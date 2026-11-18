#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스
        printf("[Child] Hello, world! Pid=%d\n", (int)getpid());
    } else {
        // 부모 프로세스
        printf("[Parent] Hello, world! Pid=%d\n", (int)getpid());
    }

    return 0;
}
