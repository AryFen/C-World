#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct ListNode {
  int data;
  struct ListNode *npx;
};

void Insert(struct ListNode **head, int data);
void ListPrint(struct ListNode *head);

struct ListNode* XOR (struct ListNode *a, struct ListNode *b) {

  return (struct ListNode*) ((uintptr_t) (a) ^ (uintptr_t) (b));

}

int main(void) {

  struct ListNode *head = NULL;
  Insert(&head, 10);
  printf("\n");
  Insert(&head, 20);
  printf("\n");
  Insert(&head, 30);
  printf("\n");
  Insert(&head, 40);
  printf("\n");
  ListPrint(head);
}

void Insert(struct ListNode **head, int data) {

  struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
  newNode->data = data;

  newNode->npx = XOR(*head, NULL);

  printf("Value of newNode->npx: %p\n", newNode->npx);
  printf("newNode: %p\n", newNode);

  if (*head != NULL) {

    struct ListNode *next = XOR((*head)->npx, NULL);
    printf("next: %p\n", next);
    (*head)->npx = XOR(newNode, next);
    printf("Value of head->npx: %p\n", (*head)->npx);

  }

  *head = newNode;
}

void ListPrint(struct ListNode *head) {

  struct ListNode *curr = head;
  struct ListNode *prev = NULL;
  struct ListNode *next;

  while (curr != NULL) {

    printf("%d\n", curr->data);
    next = XOR(prev, curr->npx);

    prev = curr;
    curr = next;
  }
}