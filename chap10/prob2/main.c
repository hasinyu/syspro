#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    struct student *next;
};

int main(void) {
    struct student *head = NULL;
    int id, count = 0;
    char name[20];

    printf("학번과 이름을 입력하세요\n");
    while (scanf("%d", &id) == 1) {
        if (scanf("%19s", name) != 1) {
            break;
        }
        struct student *node = malloc(sizeof(struct student));
        if (node == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            return 1;
        }
        node->id = id;
        strcpy(node->name, name);
        node->next = head;
        head = node;
        count++;
    }

    printf("\n* 학생 정보(역순) *\n");
    struct student *cur = head;
    while (cur != NULL) {
        printf("학번: %d 이름: %s\n", cur->id, cur->name);
        struct student *temp = cur;
        cur = cur->next;
        free(temp);
    }
    printf("총 %d 명입니다.\n", count);

    return 0;
}
