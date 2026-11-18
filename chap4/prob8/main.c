#include <stdio.h>
#include <unistd.h>

int main() {
    printf("줄 바꿈 없는 출력 ");
    fflush(stdout); // 버퍼를 강제로 비워 즉시 출력되게 함
    
    sleep(2); // 2초 대기
    
    printf("\n줄 바꿈이 있는 출력\n");
    return 0;
}
