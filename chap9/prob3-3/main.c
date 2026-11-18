#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [<args>...]\n", argv[0]);
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // execvp를 이용해 전달받은 인자 실행 (argv 파인터 배열의 두 번째 요소부터 전달)
        execvp(argv[1], &argv[1]);
        fprintf(stderr, "execvp failed\n");
        exit(1);
    } else {
        // 부모 프로세스는 자식이 끝날 때까지 대기
        pid_t child_pid = wait(&status);
        printf("[%d] child process %d end\n", (int)getpid(), (int)child_pid);
        if (WIFEXITED(status)) {
            printf("      end code %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
