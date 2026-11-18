#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *d;
    char *dir;

    if (argc == 1)
        dir = ".";
    else
        dir = argv[1];

    if ((dp = opendir(dir)) == NULL) {
        perror("opendir 오류");
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        printf("%s %lu\n", d->d_name, (unsigned long)d->d_ino);
    }

    closedir(dp);
    return 0;
}
