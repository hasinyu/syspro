#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node *top, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = top->next;
    top->next = new_node;
}

int pop(struct node *top) {
    if (top->next == NULL) {
        return -1;
    }
    struct node *temp = top->next;
    int val = temp->data;
    top->next = temp->next;
    free(temp);
    return val;
}

int main(void) {
    struct node top = {0, NULL};
    int val;

    while (scanf("%d", &val) == 1 && val > 0) {
        push(&top, val);
    }

    printf("Print stack\n");
    while (top.next != NULL) {
        printf("%d\n", pop(&top));
    }

    return 0;
}
