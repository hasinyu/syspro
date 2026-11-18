#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output_file> <command> [args...]\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            perror("open");
            exit(1);
        }

        // 표준 출력을 지정한 파일로 재지정
        dup2(fd, STDOUT_FILENO);
        close(fd);

        execvp(argv[2], &argv[2]);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
        printf("Command output saved to %s\n", argv[1]);
    }

    return 0;
}
