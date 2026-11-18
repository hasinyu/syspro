#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // 테스트용 입력 파일 생성 또는 열기
    // (필요시 input.txt 파일을 미리 생성하거나 아래 코드가 실행되도록 합니다)
    fd = open("input.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // 표준 입력(stdin, 0)을 파일 descriptor로 복제 (입력 재지정)
    if (dup2(fd, STDIN_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }
    close(fd);

    char buf[256];
    int n = read(STDIN_FILENO, buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';
        printf("Input Redirection Test - Read: %s", buf);
    } else {
        printf("No data read from redirected input.\n");
    }

    return 0;
}
