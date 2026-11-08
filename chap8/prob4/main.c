#include <stdio.h>
#include <stdlib.h>

static void exit_handler1(void) {
    printf("first exit handler\n");
}

static void exit_handler2(void) {
    printf("second exit handler\n");
}

int main(int argc, char *argv[]) {
    if (atexit(exit_handler1) != 0) {
        perror("atexit error for exit_handler1");
        return 1;
    }
    if (atexit(exit_handler2) != 0) {
        perror("atexit error for exit_handler2");
        return 1;
    }
    
    printf("main done\n");
    return 0;
}
