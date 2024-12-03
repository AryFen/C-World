#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *next;
};

int ListLength(struct ListNode *current);
void ListPrint(struct ListNode *curr);
void AddFront(struct ListNode** head, int newData);
void AddAfter(int index, int newData, struct ListNode *curr);
void AddLast(struct ListNode *curr, int newData);
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

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  ListPrint(head);
  printf("Length: %d\n", ListLength(head));
  // AddAfter(3, 10, head);
  // AddFront(&head, 5);
  // AddLast(head, 20);
  // DeleteFirst(&head);
  // DeleteAfter(head, 2);
  DeleteLast(head);
  ListPrint(head);
  printf("Length: %d\n", ListLength(head));
}

int ListLength(struct ListNode *current) {
  
  int count = 0;

  while (current != NULL) {
    count++;
    current = current->next;
  }

   return count;
}

void AddFront(struct ListNode** head, int newData) {
  struct ListNode *newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
  newNode->data = newData;
  newNode->next = (*head);
  *head = newNode;
}

void AddAfter(int index, int newData, struct ListNode *curr) {

  int count = 0;
  struct ListNode *newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode *temp = NULL;

  while (curr != NULL) {
    if (count == index - 1) {
      temp = curr->next;
      curr->next = newNode;
      newNode->data = newData;
      newNode->next = temp;
      break;
    }
    curr = curr->next;
    count++;
  }
}

void AddLast(struct ListNode *curr, int newData) {

  struct ListNode *newNode = (struct ListNode*) malloc(sizeof(struct ListNode));

  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = newNode;
  newNode->data = newData;
  newNode->next = NULL;
}

void DeleteFirst(struct ListNode **head) {
  struct ListNode *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void DeleteAfter(struct ListNode *curr, int index) {

  int count = 0;

  int length = ListLength(curr);

  if (length <= index) {
    printf("Node Does Not Exist!\n");
    return;
  }

  while (curr != NULL) {

    if (count == index - 1) {
      struct ListNode *temp = curr->next->next;
      free(curr->next);
      curr->next = temp;
    }
    curr = curr->next;
    count++;
  }
}

void DeleteLast(struct ListNode *curr) {

  while (curr->next->next != NULL) {
    curr = curr->next;
  }

  free(curr->next);
  curr->next = NULL;
}

void ListPrint(struct ListNode *curr) {

  int count = 0;

  while (curr != NULL) {
    count++;
    printf("%d: %d\n", count, curr->data);
    curr = curr->next;
  }
}