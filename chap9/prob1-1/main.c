#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("[%d] Process start\n", (int)getpid());

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("[%d] Process : return value %d\n", (int)getpid(), (int)pid);
    } else {
        printf("[%d] Process : return value %d\n", (int)getpid(), (int)pid);
    }

    return 0;
}
