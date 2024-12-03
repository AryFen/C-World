#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *ptrdiff;
};

struct ListNode * xor(struct ListNode *a, struct ListNode *b) {
  return (struct ListNode*) ((unsigned long int)a ^ (unsigned long int)b);
}

void ListPrintForwards(struct ListNode *head);
int ListLength(struct ListNode *head);
void AddFront(struct ListNode** head, int newData);
void AddAfter(struct ListNode* head, int newData, int index);
void DeleteFront(struct ListNode** head);

int main(void) {

  struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode *second = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode *third = (struct ListNode*)malloc(sizeof(struct ListNode));

  head->data = 1;
  head->ptrdiff = xor(NULL, second);

  second->data = 2;
  second->ptrdiff = xor(head, third);

  third->data = 3;
  third->ptrdiff = xor(second, NULL);

  /*

  int* i;
  char* y;
  float* f;

  printf("%lu\n%lu\n%lu\n%lu\n", sizeof(i), sizeof(y), sizeof(f), sizeof(struct ListNode*));

  */

  ListPrintForwards(head);
  AddAfter(head, 10, 2);
  // printf("%d", ListLength(head));
  printf("\n");
  ListPrintForwards(head);
}

void ListPrintForwards(struct ListNode *head) {

  /*

  printf("%d\n", head->data);
  struct ListNode *second = xor(head->ptrdiff, NULL);
  printf("%d\n", second->data);
  struct ListNode *third = xor(second->ptrdiff, head);
  printf("%d\n", third->data);

  */

  struct ListNode *curr = head;
  struct ListNode *prev = NULL;
  struct ListNode *next;

  while (curr != NULL) {

    printf("%d\n", curr->data);

    /*
    printf("P: %p\n", prev);
    printf("CPD: %p\n", curr->ptrdiff);
    printf("N: %p\n", next);
    */
    next = xor(prev, curr->ptrdiff);

    prev = curr;
    curr = next;
  }
}

int ListLength(struct ListNode *head) {

  struct ListNode *curr = head;
  struct ListNode *prev = NULL;
  struct ListNode *next;
  int count = 0;

  while (curr != NULL) {

    next = xor(prev, curr->ptrdiff);
    prev = curr;
    curr = next;
    count++;
  }
  
  return count;
}

void AddFront(struct ListNode** head, int newData) {

  struct ListNode *newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
  newNode->data = newData;

  struct ListNode *nextHead = xor((*head)->ptrdiff, NULL);

  newNode->ptrdiff = xor(NULL, *head);
  (*head)->ptrdiff = xor(newNode, nextHead);

  *head = newNode; 
}

void AddAfter(struct ListNode* head, int newData, int index) {

  if (index < 1) {
    return;
  }

  struct ListNode *curr = head;
  struct ListNode *prev = NULL;
  struct ListNode *next;

  struct ListNode *curr1 = head;
  struct ListNode *prev1 = NULL;
  struct ListNode *next1;

  struct ListNode *newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
  newNode->data = newData;

  int count = 1;

  while (1) {

    if (count < index) {

      next = xor(prev, curr->ptrdiff);
      prev = curr;
      curr = next;
      count++;
    }
    else {
      break;
    }
  }

  if (index != 2) {
    for (int i = 0; i < 2; i++) {
      next1 = xor(prev1, curr1->ptrdiff);
      prev1 = curr1;
      curr1 = next1;
    }
  }

  newNode->ptrdiff = xor(curr, xor(curr->ptrdiff, prev));
  curr->ptrdiff = xor(prev, newNode);

  struct ListNode *nextNewNode = xor(newNode->ptrdiff, curr);

  if (ListLength(head) == 3 && index == 2) {
    nextNewNode->ptrdiff = xor(newNode, NULL);
  }
  else {
    nextNewNode->ptrdiff = xor(newNode, curr1);
  }
} 

void DeleteFront(struct ListNode** head) {

  struct ListNode *headNext = xor(NULL, (*head)->ptrdiff);
  struct ListNode *secondNext = xor(*head, headNext->ptrdiff);

  struct ListNode *temp = (*head);
  *head = headNext;
  free(temp);

  (*head)->ptrdiff = xor(NULL, secondNext);
}