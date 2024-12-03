#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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

int isOperand(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
int Prec(char ch)
{
  switch (ch)
  {
  case '+':
  case '-':
    return 1;

  case '*':
  case '/':
    return 2;

  case '^':
    return 3;
  }
  return -1;
}

int isOperator(char character) {
  if (character == '^' || character == '*' || character == '/' || character == '+' || character == '-') {
    return 1;
  }
  else {
    return 0;
  }
}
 
// The main function that
// converts given infix expression
// to postfix expression.
void infixToPostfix(char* infix)
{
  struct Stack *stack = createStack(1);

  for (int i = 0; i < strlen(infix); i++) {
    if (isOperand(infix[i]) == 1) {
      printf("%c", infix[i]);
    }
    if (infix[i] == '(') {
      push(stack, infix[i]);
    }
    else if (infix[i] == ')') {
      while (!isEmpty(stack)) {
        if (peek(stack) != '(') {
          printf("%c",  pop(stack));
        }
        else {
          pop(stack);
          continue;
        }
      }
    }

    if (isOperator(infix[i])) {
      while (!isEmpty(stack)) {
        if (peek(stack) == '(') {
          break;
        }
        else if (Prec(infix[i] <= Prec(peek(stack)))) {
          pop(stack);
        }
      }
      push(stack, infix[i]);
      
    }

    while (!isEmpty(stack)) {
      printf("%c", pop(stack));
    }
  }
}

// Driver program to test above functions
int main()
{

  FILE *file;
  char exp[60];

  file = fopen("expressions.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return(-1);
  }
  fgets(exp, 60, file);
  fclose(file);
  infixToPostfix(exp);
  return 0;
}