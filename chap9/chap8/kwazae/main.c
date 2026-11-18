#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

extern char **environ;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-e [name]] [-u] [-g] [-i] [-p]\n", argv[0]);
        return 1;
    }

    char *opt = argv[1];

    if (strcmp(opt, "-e") == 0) {
        if (argc > 2) {
            char *val = getenv(argv[2]);
            if (val != NULL) {
                printf("%s=%s\n", argv[2], val);
            }
        } else {
            char **env = environ;
            while (*env != NULL) {
                printf("%s\n", *env);
                env++;
            }
        }
    } else if (strcmp(opt, "-u") == 0) {
        uid_t ruid = getuid();
        uid_t euid = geteuid();
        struct passwd *rpwd = getpwuid(ruid);
        struct passwd *epwd = getpwuid(euid);

        printf("My Realistic User ID : %d(%s)\n", ruid, rpwd ? rpwd->pw_name : "");
        printf("My Valid User ID : %d(%s)\n", euid, epwd ? epwd->pw_name : "");
    } else if (strcmp(opt, "-g") == 0) {
        gid_t rgid = getgid();
        gid_t egid = getegid();
        struct group *rgrp = getgrgid(rgid);
        struct group *egrp = getgrgid(egid);

        printf("My Realistic Group ID : %d(%s)\n", rgid, rgrp ? rgrp->gr_name : "");
        printf("My Valid Group ID : %d(%s)\n", egid, egrp ? egrp->gr_name : "");
    } else if (strcmp(opt, "-i") == 0) {
        printf("my process number : [%d]\n", (int)getpid());
    } else if (strcmp(opt, "-p") == 0) {
        printf("my parent's process number : [%d]\n", (int)getppid());
    }

    return 0;
}
