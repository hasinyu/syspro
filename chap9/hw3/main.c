#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD 256
#define MAX_ARGS 32

int main() {
    char cmd[MAX_CMD];
    char *args[MAX_ARGS];

    while (1) {
        printf("myshell> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) break;
        cmd[strcspn(cmd, "\n")] = '\0';

        if (strlen(cmd) == 0) continue;
        if (strcmp(cmd, "exit") == 0) break;

        int background = 0;
        int i = 0;
        char *token = strtok(cmd, " \t");
        while (token != NULL && i < MAX_ARGS - 1) {
            if (strcmp(token, "&") == 0) {
                background = 1;
            } else {
                args[i++] = token;
            }
            token = strtok(NULL, " \t");
        }
        args[i] = NULL;

        if (args[0] == NULL) continue;

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else if (pid > 0) {
            if (!background) {
                waitpid(pid, NULL, 0);
            } else {
                printf("[Background PID: %d]\n", pid);
            }
        } else {
            perror("fork");
        }
    }

    return 0;
}
