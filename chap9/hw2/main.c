#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(1);
        exit(10);
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("Child 2: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(2);
        exit(20);
    }

    int status;
    pid_t wpid;
    while ((wpid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            printf("Parent: Child %d exited with status %d\n", wpid, WEXITSTATUS(status));
        }
    }

    return 0;
}
