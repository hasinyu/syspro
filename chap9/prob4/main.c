#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>  // 이 줄을 추가합니다!

int my_system(const char *cmdstring) {
    pid_t pid;
    int status;

    if (cmdstring == NULL)
        return 1;

    pid = fork();
    if (pid < 0) {
        return -1;
    } else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    } else {
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1;
                break;
            }
        }
    }
    return status;
}

int main() {
    printf("--- my_system test start ---\n");
    my_system("ls -l");
    printf("--- my_system test end ---\n");
    return 0;
}
