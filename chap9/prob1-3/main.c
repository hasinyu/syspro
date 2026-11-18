#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Fork 1 failed\n");
        return 1;
    } else if (pid1 == 0) {
        // 첫 번째 자식 프로세스
        printf("[Child 1] : Hello, world ! pid=%d\n", (int)getpid());
    } else {
        // 부모 프로세스에서 두 번째 자식 생성
        pid2 = fork();

        if (pid2 < 0) {
            fprintf(stderr, "Fork 2 failed\n");
            return 1;
        } else if (pid2 == 0) {
            // 두 번째 자식 프로세스
            printf("[Child 2] : Hello, world ! pid=%d\n", (int)getpid());
        } else {
            // 부모 프로세스
            printf("[PARENT] : Hello, world ! pid=%d\n", (int)getpid());
        }
    }

    return 0;
}
