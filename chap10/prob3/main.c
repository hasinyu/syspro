#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char src[] = "Do you like Linux?";
    char *str = malloc(strlen(src) + 15);
    if (str == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    memcpy(str, src, strlen(src) + 1);
    printf("%s\n", str);

    memset(str + 12, 'l', 1);
    printf("%s\n", str);

    char *p = memchr(str, 'l', strlen(str));
    if (p != NULL) {
        printf("%s\n", p);
    }

    memmove(str + 12, str + 7, 10);
    str[22] = '\0';
    printf("%s\n", str);

    free(str);
    return 0;
}
