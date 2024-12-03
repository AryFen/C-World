// Make a stack with 2 queues

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Stack {
  struct Node* Queue1;
  struct Node* rear;
  struct Node* Queue2;
  struct Node* rear2;
  int size;
};

void Push(struct Stack* stack, int data);
void Pop(struct Stack* stack);
void Clear(struct Node **head);
void ListPrint(struct Node *curr);

int main(void) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->Queue1 = malloc(sizeof(struct Node));
  stack->rear = stack->Queue1;
  stack->Queue2 = malloc(sizeof(struct Node));
  stack->rear2 = stack->Queue2;
  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);
  ListPrint(stack->Queue1);
  printf("\n");
  Pop(stack);
  printf("\n");
  ListPrint(stack->Queue1);
  printf("\n");
  Push(stack, 5);
  ListPrint(stack->Queue1);
  printf("\n");
  Pop(stack);
  printf("\n");
  ListPrint(stack->Queue1);
}

void Push(struct Stack* stack, int data) {
  stack->rear->data = data;
  stack->rear->next = malloc(sizeof(struct Node));
  stack->rear = stack->rear->next;
  stack->size++;
} 

void Pop(struct Stack* stack) {

  int arr[stack->size];
  int arr2[stack->size];
  
  struct Node* temp = stack->Queue1;

  for (int i = 0; i < stack->size; i++) {
    arr[i] = temp->data;
    temp = temp->next;
  }

  Clear(&stack->Queue1);

  for (int i = stack->size - 1; i >= 0; i--) {
    stack->rear2->data = arr[i];;
    stack->rear2->next = malloc(sizeof(struct Node));
    stack->rear2 = stack->rear2->next;
  }

  temp = stack->Queue2;
  printf("Popped: %d\n", temp->data);
  stack->Queue2 = stack->Queue2->next;
  free(temp);
  stack->size--;

  stack->Queue1 = malloc(sizeof(struct Node));
  stack->rear = stack->Queue1;

  struct Node* temp2 = stack->Queue2;

  for (int i = 0; i < stack->size; i++) {
    arr2[i] = temp2->data;
    temp2 = temp2->next;
  }

  for (int i = stack->size - 1; i >= 0; i--) {
    stack->rear->data = arr2[i];
    stack->rear->next = malloc(sizeof(struct Node));
    stack->rear = stack->rear->next;
  }  

  Clear(&stack->Queue2);

  stack->Queue2 = malloc(sizeof(struct Node));
  stack->rear2 = stack->Queue2;
}

void Clear(struct Node **head) {
  while ((*head) != NULL) {
    struct Node *temp = (*head);
    (*head) = temp->next;
    free(temp);
  }
}

void ListPrint(struct Node *curr) {

  int count = 0;

  while (curr->next != NULL) {
    count++;
    printf("%d: %d\n", count, curr->data);
    curr = curr->next;
  }
}