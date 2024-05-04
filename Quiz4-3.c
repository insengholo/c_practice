#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head; 
    head = p; 
    return head;
}

void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

ListNode* merge(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    ListNode* p = head1;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = head2;
    return head1;
}

ListNode* reverse_list(ListNode* head) {
    ListNode *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    printf("");
    print_list(head1);

    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    printf("");
    print_list(head2);

    ListNode* merged_head = merge(head1, head2);
    printf("");
    print_list(merged_head);

    ListNode* reversed_head = reverse_list(merged_head);
    printf("역순의 리스트: ");
    print_list(reversed_head);

    while (reversed_head != NULL) {
        ListNode* removed = reversed_head;
        reversed_head = removed->link;
        free(removed);
    }

    return 0;
}
