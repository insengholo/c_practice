#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char data[100];
    struct ListNode* link;
} ListNode;

int search(ListNode* head, char* value);
ListNode* insert_first(ListNode* head, char* value);
void print_list(ListNode* head);
ListNode* merge(ListNode* head1, ListNode* head2);
ListNode* reverse(ListNode* head);

ListNode* insert_first(ListNode* head, char* value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    strcpy(p->data, value);
    p->link = head; 
    head = p; 
    return head;
}

void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%s->", p->data);
    printf("NULL\n");
}

int search(ListNode* head, char* value) {
    ListNode* p = head;
    while (p != NULL) {
        if (strcmp(p->data, value) == 0) {
            printf("리스트에서 %s을(를) 찾았습니다.\n", value);
            return 1;
        }
        p = p->link;
    }
    printf("%s은(는) 리스트에 없습니다.\n", value);
    return 0;
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

ListNode* reverse(ListNode* head) {
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
    ListNode* head = NULL;
    head = insert_first(head, "APPLE");
    print_list(head);
    head = insert_first(head, "KIWI");
    print_list(head);
    head = insert_first(head, "BANANA");
    print_list(head);

    search(head, "BANANA");

    while (head != NULL) {
        ListNode* removed = head;
        head = head->link;
        free(removed);
    }

    return 0;
}
