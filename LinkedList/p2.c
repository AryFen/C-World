#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *next;
  struct ListNode *prev;
};

int ListLength(struct ListNode *curr);
void PrintListForward(struct ListNode *curr);
void PrintListBackward(struct ListNode *curr);
void AddFront(struct ListNode **curr, int data);
void AddAfter(struct ListNode *curr, int data, int index);
void AddLast(struct ListNode *curr, int data);
void DeleteFirst(struct ListNode **head);
void DeleteAfter(struct ListNode *curr, int index);
void DeleteLast(struct ListNode *curr);

int main(void) {

  struct ListNode* head = NULL;
  struct ListNode* second = NULL;
  struct ListNode* third = NULL;

  head = (struct ListNode*)malloc(sizeof(struct ListNode));
  second = (struct ListNode*)malloc(sizeof(struct ListNode));
  third = (struct ListNode*)malloc(sizeof(struct ListNode));

  head->data = 1;
  head->next = second;
  head->prev = NULL;

  second->data = 2;
  second->next = third;
  second->prev = head;

  third->data = 3;
  third->next = NULL;
  third->prev = second;

  PrintListForward(head);
  PrintListBackward(head);
  // AddFront(&head, 4);
  // AddLast(head, 4);
  // AddAfter(head, 10, 3);
  // DeleteFirst(&head);
  // DeleteAfter(head, 1);
  DeleteLast(head);
  printf("\n");
  PrintListForward(head);
  PrintListBackward(head);
}

int ListLength(struct ListNode *curr) {
  
  int count = 0;

  while (curr != NULL) {
    curr = curr->next;
    count++;
  }

  return count;
}

void PrintListForward(struct ListNode *curr) {
  
  while (curr != NULL) {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
}

void PrintListBackward(struct ListNode *curr) {
  
  while (curr->next != NULL) {
    curr = curr->next;
  }

  while (curr != NULL) {
    printf("%d\n", curr->data);
    curr = curr->prev;
  }
}

void AddFront(struct ListNode **curr, int data) {

  struct ListNode *newNode;
  newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

  newNode->next = (*curr);
  *curr = newNode;
  newNode->next->prev = newNode;
  newNode->prev = NULL;
  newNode->data = data;
} 

void AddLast(struct ListNode *curr, int data) {
  
  struct ListNode *newNode;
  newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = newNode;
  newNode->next = NULL;
  newNode->prev = curr;
  newNode->data = data;
}

void AddAfter(struct ListNode *curr, int data, int index) {

  if (index >= ListLength(curr)) {
    printf("Index is too high!");
    return;
  }


  struct ListNode *newNode;
  struct ListNode *temp;
  newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
  int count = 0;

  while (count != index - 1) {
    count++;
    curr = curr->next;
  }

  temp = curr->next;
  curr->next = newNode;
  newNode->prev = curr;
  newNode->data = data;
  newNode->next = temp;
  temp->prev = newNode;
}

void DeleteFirst(struct ListNode **head) {
  struct ListNode *temp = *head;
  *head = (*head)->next;
  free(temp);
  (*head)->prev = NULL;
}

void DeleteAfter(struct ListNode *curr, int index) {

  if (index >= ListLength(curr) - 1) {
    printf("Index is too high!");
    return;
  }

  int count = 0;

  while (count != index - 1) {
    curr = curr->next;
    count++;
  }

  struct ListNode *temp = curr->next->next;
  free(curr->next);
  curr->next = temp;
  temp->prev = curr;
}

void DeleteLast(struct ListNode *curr) {
  
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  free(curr->next);
  curr->next = NULL;
}