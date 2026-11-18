#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

void print_stat(char *path, char *file, int opt_i, int opt_p, int opt_Q) {
    struct stat buf;
    char filename[512];
    snprintf(filename, sizeof(filename), "%s/%s", path, file);

    if (lstat(filename, &buf) < 0) {
        perror("lstat 오류");
        return;
    }

    if (opt_i) {
        printf("%lu ", (unsigned long)buf.st_ino);
    }

    printf("%c", S_ISDIR(buf.st_mode) ? 'd' : (S_ISLNK(buf.st_mode) ? 'l' : '-'));
    printf("%c", (buf.st_mode & S_IRUSR) ? 'r' : '-');
    printf("%c", (buf.st_mode & S_IWUSR) ? 'w' : '-');
    printf("%c", (buf.st_mode & S_IXUSR) ? 'x' : '-');
    printf("%c", (buf.st_mode & S_IRGRP) ? 'r' : '-');
    printf("%c", (buf.st_mode & S_IWGRP) ? 'w' : '-');
    printf("%c", (buf.st_mode & S_IXGRP) ? 'x' : '-');
    printf("%c", (buf.st_mode & S_IROTH) ? 'r' : '-');
    printf("%c", (buf.st_mode & S_IWOTH) ? 'w' : '-');
    printf("%c ", (buf.st_mode & S_IXOTH) ? 'x' : '-');

    printf("%2ld ", (long)buf.st_nlink);
    printf("%s ", getpwuid(buf.st_uid)->pw_name);
    printf("%s ", getgrgid(buf.st_gid)->gr_name);
    printf("%8ld ", (long)buf.st_size);

    char time_str[32];
    struct tm *tm_info = localtime(&buf.st_mtime);
    strftime(time_str, sizeof(time_str), "%b %d %H:%M", tm_info);
    printf("%s ", time_str);

    if (opt_Q) {
        printf("\"%s\"", file);
    } else {
        printf("%s", file);
        if (opt_p && S_ISDIR(buf.st_mode)) {
            printf("/");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *d;
    char *dir = ".";
    int opt_i = 0, opt_p = 0, opt_Q = 0;
    int opt;

    while ((opt = getopt(argc, argv, "ipQ")) != -1) {
        switch (opt) {
            case 'i':
                opt_i = 1;
                break;
            case 'p':
                opt_p = 1;
                break;
            case 'Q':
                opt_Q = 1;
                break;
            default:
                fprintf(stderr, "사용법: %s [-i] [-p] [-Q] [디렉터리]\n", argv[0]);
                exit(1);
        }
    }

    if (optind < argc) {
        dir = argv[optind];
    }

    if ((dp = opendir(dir)) == NULL) {
        perror("opendir 오류");
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        print_stat(dir, d->d_name, opt_i, opt_p, opt_Q);
    }

    closedir(dp);
    return 0;
}
