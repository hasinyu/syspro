#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;

    // 표준 출력을 파일(redir.txt)로 재지정하기 위해 파일을 쓰기 전용으로 열기 (없으면 생성)
    fd = open("redir.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // 표준 출력(stdout, 파일Descriptor 1)을 열린 파일 fd로 복제(재지정)
    dup2(fd, STDOUT_FILENO);
    close(fd);

    // 이후 printf로 출력하는 내용은 화면이 아니라 redir.txt 파일에 기록됨
    printf("Hello, Redirection!\n");
    printf("This output is redirected to a file.\n");

    return 0;
}
