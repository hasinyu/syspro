#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("HOME = %s\n", getenv("HOME"));
    printf("SHELL = %s\n", getenv("SHELL"));
    printf("PATH = %s\n", getenv("PATH"));
    
    return 0;
}
