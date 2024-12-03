#include <stdio.h>

#define SIZE 10
int arr[SIZE];
int top = -1;

int IsStackFull();
int IsStackEmpty();
void Push(int data);
int Pop();
int Top();

int main(void) {
  Push(10);
  printf("1: %d\n", Top());
  Push(20);
  printf("2: %d\n", Top());
  Push(30);
  printf("3: %d\n", Top());
  printf("Post-Pop: %d\n", Pop());
  printf("End: %d\n", Top());
}

void Push(int data) {
  if (IsStackFull() == 0) {
    arr[top + 1] = data;  
    top++;
  }
  else {
    printf("Stack is Full\n");
  }
}

int Pop() {
  if (IsStackEmpty() == 0) {
    int value = arr[top];
    arr[top] = 0;
    top--;
    return value;
  }
  else {
    printf("Stack is Empty\n");
  }
}

int Top() {
  return arr[top];
}

int IsStackEmpty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}

int IsStackFull() {
  if (top == SIZE) {
    return 1;
  }
  return 0;
}