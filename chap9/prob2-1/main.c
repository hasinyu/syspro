#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int status;

    printf("[%d] parental process strat\n", (int)getpid());

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스
        printf("[%d] child process start\n", (int)getpid());
        exit(1);
    } else {
        // 부모 프로세스
        pid_t child_pid = wait(&status);
        printf("[%d] child process %d end\n", (int)getpid(), (int)child_pid);
        
        if (WIFEXITED(status)) {
            printf("      end code %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
