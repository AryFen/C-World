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
void ListPrint(struct Stack *stack);

int main(void) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->Queue1 = malloc(sizeof(struct Node));
  stack->rear = stack->Queue1;
  stack->Queue2 = NULL;
  //Push(stack, 2);
  //Push(stack, 3);
  Pop(stack);
  Pop(stack);
  Pop(stack);
  Pop(stack);
  ListPrint(stack);
  Push(stack, 1);
  ListPrint(stack);
  /* 
  printf("Size: %d\n", stack->size);
  printf("\n");
  Pop(stack);
  ListPrint(stack);
  printf("Size: %d\n", stack->size);
  printf("\n");
  Push(stack, 2);
  ListPrint(stack);
  printf("Size: %d\n", stack->size);
  printf("\n");
  Pop(stack);
  ListPrint(stack);
  printf("Size: %d\n", stack->size);
  printf("\n");
  Pop(stack);
  ListPrint(stack);
  printf("Size: %d\n", stack->size);
  printf("\n");
  Push(stack, 1);
  ListPrint(stack);
  printf("Size: %d\n", stack->size);
  */
}

void Push(struct Stack* stack, int data) {
  if (stack->Queue1 == NULL) {
    stack->rear2->data = data;
    stack->rear2->next = malloc(sizeof(struct Node));
    stack->rear2 = stack->rear2->next;
    stack->size++;
    return;
  }
  else {
    stack->rear->data = data;
    stack->rear->next = malloc(sizeof(struct Node));
    stack->rear = stack->rear->next;
    stack->size++;
    return;
  }
} 

void Pop(struct Stack* stack) {
  if (stack->Queue1 != NULL) {
    if (stack->size == 0) {
      return;
    }
    struct Node* temp = stack->Queue1;
    stack->Queue2 = malloc(sizeof(struct Node));
    stack->rear2 = stack->Queue2;
    if (stack->size == 1) {
      Clear(&stack->Queue1);
      stack->size--;
      return;
    }
    for (int i = 0; i < stack->size - 1; i++) {
      stack->rear2->data = temp->data;
      temp = temp->next;
      stack->rear2->next = malloc(sizeof(struct Node));
      stack->rear2 = stack->rear2->next;
    } 
    stack->size--;
    Clear(&stack->Queue1);
  }
  else {
    if (stack->size == 0) {
      return;
    }
    struct Node* temp = stack->Queue2;
    stack->Queue1 = malloc(sizeof(struct Node));
    stack->rear = stack->Queue1;
    if (stack->size == 1) {
      Clear(&stack->Queue2);
      stack->size--;
      return;
    }
    for (int i = 0; i < stack->size - 1; i++) {
      stack->rear->data = temp->data;
      temp = temp->next;
      stack->rear->next = malloc(sizeof(struct Node));
      stack->rear = stack->rear->next;
    } 
    stack->size--;
    Clear(&stack->Queue2);
  }
}

void Clear(struct Node **head) {
  while ((*head) != NULL) {
    struct Node *temp = (*head);
    (*head) = temp->next;
    free(temp);
  }
  (*head) = NULL;
}

void ListPrint(struct Stack *stack) {

  int count = 0;

  if (stack->size == 0) {
    printf("Stack is Empty\n");
  }

  if (stack->Queue1 != NULL) {
    struct Node* curr = stack->Queue1;
    while (curr->next != NULL) {
      count++;
      printf("%d: %d\n", count, curr->data);
      curr = curr->next;
    }
  }
  else {
    struct Node* curr = stack->Queue2;
    while (curr->next != NULL) {
      count++;
      printf("%d: %d\n", count, curr->data);
      curr = curr->next;
    }
  }
}
