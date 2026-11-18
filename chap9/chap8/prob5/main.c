#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("my process number: [%d]\n", (int)getpid());
    printf("my parent process number: [%d]\n", (int)getppid());
    
    return 0;
}
