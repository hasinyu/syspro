#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    uid_t ruid = getuid();
    uid_t euid = geteuid();
    gid_t rgid = getgid();
    gid_t egid = getegid();

    struct passwd *rpwd = getpwuid(ruid);
    struct passwd *epwd = getpwuid(euid);
    struct group *rgrp = getgrgid(rgid);
    struct group *egrp = getgrgid(egid);

    printf("My Realistic User ID: %d(%s)\n", ruid, rpwd ? rpwd->pw_name : "");
    printf("My Valid User ID: %d(%s)\n", euid, epwd ? epwd->pw_name : "");
    printf("My Realistic Group ID: %d(%s)\n", rgid, rgrp ? rgrp->gr_name : "");
    printf("My Valid Group ID: %d(%s)\n", egid, egrp ? egrp->gr_name : "");

    return 0;
}
