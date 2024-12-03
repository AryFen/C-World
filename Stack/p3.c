#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
  int top;
  int capacity;
  int *arr;
};

struct Stack * createStack(int capacity) {
  struct Stack *stack = malloc(sizeof(struct Stack));

  if (!stack) {
    return NULL;
  }

  stack->capacity = capacity;
  stack->top = -1;
  stack->arr = malloc(stack->capacity * sizeof(int));
  
  if (!stack->arr) {
    return NULL;
  }

  return stack;
}

int isEmpty(struct Stack *stack) {
  return (stack->top == -1);
}

int size(struct Stack *stack) {
  return (stack->top + 1);
}

int isFull(struct Stack *stack) {
  return (stack->top == stack->capacity - 1);
}

void doubleStack(struct Stack *stack) {
  stack->capacity *= 2;
  stack->arr = realloc(stack->arr, stack->capacity * sizeof(int));
}

void push(struct Stack *stack, int data) {
  if (isFull(stack)) {
    doubleStack(stack);
  }
  stack->arr[++stack->top] = data;
}

int pop(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is Empty\n");
    return INT_MIN;
  }
  else {
    return (stack->arr[stack->top--]);
  }
}

int peek(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is Empty\n");
    return INT_MIN;
  }
  else {
    return (stack->arr[stack->top]);
  }
}

void deleteStack(struct Stack *stack) {
  if (stack) {
    if (stack->arr) {
      free(stack->arr);
    }
    free(stack);
  }
}

int main(void) {
  struct Stack *stack = createStack(1);

  printf("Size: %d\n", size(stack));
  printf("Capacity: %d\n", stack->capacity);
  push(stack, 1);
  printf("Size: %d\n", size(stack));
  printf("Capacity: %d\n", stack->capacity);
  push(stack, 2);
  printf("Size: %d\n", size(stack));
  printf("Capacity: %d\n", stack->capacity);
  push(stack, 3);
  printf("Size: %d\n", size(stack));
  printf("Capacity: %d\n", stack->capacity);
}

