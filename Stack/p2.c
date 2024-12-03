#include <stdio.h>

int top = -1;


int IsStackFull(int size);
int IsStackEmpty();
void Push(int data, int arr[], int size);
int Pop(int arr[]);
int Top(int arr[]);

int main(void) {

  int size;

  printf("Size of Array (0 is 1): ");
  scanf("%d", &size);
  int arr[size];

  printf("\n");
  printf("1: Push, 2: Pop, 3: Top, 4: End\n");

  while(1) {

    int decision;

    printf("\nWhat would you like to do?: " );
    scanf("%d", &decision);
    printf("\n");
    
    if (decision == 1) {
      if (IsStackFull(size) == 0) {
        printf("Choose the data: ");
        int data;
        scanf("%d", &data);
        Push(data, arr, size);
      }
      else {
        printf("Stack is Full\n");
      }
    }
    else if (decision == 2) {
      if (IsStackEmpty() == 0) {
        printf("%d\n", Pop(arr));
      }
      else {
        printf("Stack is empty\n");
      }  
    }
    else if (decision == 3) {
      if (IsStackEmpty() == 0) {
        printf("Top: %d\n", Top(arr));
      }
      else {
        printf("Stack is Empty\n");
      }
    }
    else if (decision == 4) {
      return 0;
    }
    else {
      printf("Error: Choice Invalid\n");
    }
  }
}

void Push(int data, int arr[], int size) {
  if (IsStackFull(size) == 0) {
    arr[top + 1] = data;  
    top++;
  }
  else {
    printf("Stack is Full\n");
  }
}

int Pop(int arr[]) {
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

int Top(int arr[]) {
  return arr[top];
}

int IsStackEmpty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}

int IsStackFull(int size) {
  if (top == size) {
    return 1;
  }
  return 0;
}