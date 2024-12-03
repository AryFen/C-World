#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *next;
};

void CLLLength(struct ListNode *head);
void CLLPrint(struct ListNode *head);
void CLLAddAfter(struct ListNode *curr, int index, int data);
void CLLDeleteAfter(struct ListNode **curr, int index);

int main(void) {

  struct ListNode* head = NULL;
  struct ListNode* second = NULL;
  struct ListNode* third = NULL;

  head = (struct ListNode*)malloc(sizeof(struct ListNode));
  second = (struct ListNode*)malloc(sizeof(struct ListNode));
  third = (struct ListNode*)malloc(sizeof(struct ListNode));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = head;

  CLLPrint(head);
  CLLLength(head);
  // CLLAddAfter(head, 1, 6);
  // For Delete, the parameter node for Print/Length functions should not be head if head is being deleted
  CLLDeleteAfter(&third, 1);
  CLLPrint(second);
  CLLLength(second);
}

void CLLLength(struct ListNode *head) {

  /* Steps

  Create new pointer, current
  Assign head to current
  if head != current, continue

  */

  struct ListNode *curr = head;
  int count = 0;

  do {
    curr = curr->next;
    count++;
  }
  while (curr != head);

  printf("Length: %d\n", count);
}

void CLLPrint(struct ListNode *head) {
  
  struct ListNode *curr = head;
  
  do {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
  while (curr != head);
}

void CLLAddAfter(struct ListNode *curr, int index, int data) {
  
  // Works from 1

  if (index < 1) {
    printf("Invalid Index! Must Be Greater Than/Equal To 1!\n");
    return;
  }

  int count = 0;

  while (count != index - 1) {
    curr = curr->next;
    count++;
  }

  struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
  newNode->next = curr->next;
  curr->next = newNode;
  newNode->data = data;
}

void CLLDeleteAfter(struct ListNode **curr, int index) {

  // Works from 1

  if (index < 1) {
    printf("Invalid Index! Must Be Greater Than/Equal To 1!\n");
    return;
  }

  int count = 0;

  while (count != index - 1) {
    *curr = (*curr)->next;
    count++;
  }

  struct ListNode *temp = (*curr)->next->next;
  free((*curr)->next);
  (*curr)->next = temp;
}
