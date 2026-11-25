#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Real UID: %d, Effective UID: %d\n", (int)getuid(), (int)geteuid());
    printf("Real GID: %d, Effective GID: %d\n", (int)getgid(), (int)getegid());
    printf("Process ID: %d, Parent PID: %d, Process Group ID: %d\n", 
           (int)getpid(), (int)getppid(), (int)getpgrp());

    return 0;
}
