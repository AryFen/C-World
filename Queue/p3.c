#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node* Head1;
  struct Node* Head2;
  int capacity;
};

void enQueue(struct Queue* queue, int data);
void deQueue(struct Queue* queue);

void ListPrint(struct Node *curr) {

  int count = 0;

  while (curr != NULL) {
    count++;
    printf("%d: %d\n", count, curr->data);
    curr = curr->next;
  }
}

void Push(int data, struct Node **head) {
  if ((*head) == NULL) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    (*head) = newNode;
    (*head)->data = data;
    (*head)->next = NULL;
  }
  else {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = (*head);
    (*head) = newNode;
    newNode->next = temp;   
  }
}

int Pop(struct Node **head) {
  if ((*head) != NULL) {
    struct Node *temp = (*head);
    int data = temp->data;
    (*head) = temp->next;
    free(temp);
    return data;
  }
  else {
    printf("Stack Does Not Exist!\n");
    return -1;
  }
}

int Peek(struct Node **head) {
  if ((*head) != NULL) {
    return (*head)->data;
  }
  else {
    printf("Stack Does Not Exist!\n");
    return -1;
  }
}

void Clear(struct Node **head) {
  while ((*head) != NULL) {
    struct Node *temp = (*head);
    (*head) = temp->next;
    free(temp);
  }
}

int isEmpty(struct Node **head) {
  if ((*head) == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

int main(void) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  enQueue(queue, 10);
  enQueue(queue, 20);
  enQueue(queue, 30);
  printf("\n");
  ListPrint(queue->Head1);
  printf("\n");
  deQueue(queue);
  printf("\n");
  ListPrint(queue->Head1);
  printf("\n");
  deQueue(queue);
  printf("\n");
  ListPrint(queue->Head1);
  printf("\n");
  deQueue(queue);
  printf("\n");
  ListPrint(queue->Head1);
  printf("\n");
  deQueue(queue);
  printf("\n");
  ListPrint(queue->Head1);
  printf("\n");
  deQueue(queue);
  printf("\n");
  ListPrint(queue->Head1);
  enQueue(queue, 40);
  printf("\n");
  ListPrint(queue->Head1);
}

void enQueue(struct Queue* queue, int data) {

  Push(data, &queue->Head1);
  queue->capacity++;
}

void deQueue(struct Queue* queue) {

  for (int i = 0; i < queue->capacity; i++) {

    struct Node *curr = queue->Head1;

    for (int j = 0; j < i; j++) {
      curr = curr->next;
    }
    Push(curr->data, &queue->Head2);  
  }

  printf("Popped: %d\n", Pop(&queue->Head2));
  queue->capacity--;
  Clear(&queue->Head1);

  for (int i = 0; i < queue->capacity; i++) {
    
    struct Node *curr = queue->Head2;

    for (int j = 0; j < i; j++) {
      curr = curr->next;
    }
    Push(curr->data, &queue->Head1);  
  }

  Clear(&queue->Head2);
}