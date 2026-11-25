#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[20];
};

int main(void) {
    int n;
    printf("몇 명의 학생을 입력하겠습니까? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "잘못된 학생 수 입력입니다.\n");
        return 1;
    }

    struct student *arr = malloc(sizeof(struct student) * n);
    if (arr == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    printf("%d 명의 학번과 이름을 입력하세요.\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d %19s", &arr[i].id, arr[i].name) != 2) {
            fprintf(stderr, "입력 형식이 잘못되었습니다.\n");
            free(arr);
            return 1;
        }
    }

    printf("\n* 학생 정보(역순) *\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d %s\n", arr[i].id, arr[i].name);
    }

    free(arr);
    return 0;
}
