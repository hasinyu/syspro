#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("parental process start\n");

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스에서 execl을 이용해 /bin/echo 실행
        execl("/bin/echo", "echo", "hello", NULL);
        // execl 실패 시에만 실행됨
        fprintf(stderr, "execl failed\n");
        exit(1);
    }

    // 부모 프로세스
    printf("prarental process end\n");
    return 0;
}
