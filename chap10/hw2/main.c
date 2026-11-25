#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node *head, struct node *tail, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    struct node *prev = head;
    while (prev->next != NULL) {
        prev = prev->next;
    }
    prev->next = new_node;
    tail->next = new_node;
}

int delete(struct node *head, struct node *tail) {
    if (head->next == NULL) {
        return -1;
    }
    struct node *temp = head->next;
    int val = temp->data;
    head->next = temp->next;
    if (head->next == NULL) {
        tail->next = NULL;
    }
    free(temp);
    return val;
}

int main(void) {
    struct node head = {0, NULL};
    struct node tail = {0, NULL};
    int val;

    while (scanf("%d", &val) == 1 && val > 0) {
        addq(&head, &tail, val);
    }

    printf("Print queue\n");
    while (head.next != NULL) {
        printf("%d\n", delete(&head, &tail));
    }

    return 0;
}
