#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buffer[1024];
    ssize_t nbytes;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s <심볼릭링크>\n", argv[0]);
        exit(1);
    }

    if ((nbytes = readlink(argv[1], buffer, sizeof(buffer) - 1)) < 0) {
        perror("readlink 오류");
        exit(1);
    }

    buffer[nbytes] = '\0';
    write(STDOUT_FILENO, buffer, nbytes);
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}
