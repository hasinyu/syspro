#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [args...]\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스: 명령줄 인수로 받은 명령어 실행
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(1);
    } else {
        // 부모 프로세스: 자식 종료 대기
        int status;
        waitpid(pid, &status, 0);
        printf("[%d] Child process %d terminated\n", getpid(), pid);
    }

    return 0;
}
