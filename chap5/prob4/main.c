#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;

    // myfile 생성 및 쓰기 전용으로 열기 (권한 0600)
    if ((fd1 = creat("myfile", 0600)) == -1) {
        perror("creat");
        exit(1);
    }

    // 파일 디스크립터 fd1을 이용해 데이터 쓰기
    write(fd1, "Hello! Linux\n", 13);

    // dup() 함수를 이용해 파일 디스크립터 복제
    fd2 = dup(fd1);

    // 복제된 파일 디스크립터 fd2를 이용해 데이터 쓰기
    write(fd2, "Bye! Linux\n", 11);

    close(fd1);
    close(fd2);
    return 0;
}
