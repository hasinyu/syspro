#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void print_stat(char *path, char *file) {
    struct stat buf;
    char filename[512];
    snprintf(filename, sizeof(filename), "%s/%s", path, file);

    if (lstat(filename, &buf) < 0) {
        perror("lstat 오류");
        return;
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

    printf("%s\n", file);
}

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
        print_stat(dir, d->d_name);
    }

    closedir(dp);
    return 0;
}
