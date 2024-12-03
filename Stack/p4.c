#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

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
    printf("Data: %d\n", temp->data);
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

  struct Node *head = NULL;

  while (1) {

    int decision;
  
    printf("\nWhat would you like to do? (1: Push, 2: Pop, 3: Peek, 4: End):  ");
    scanf("%d", &decision);
    printf("\n");

    if (decision == 1) {

      int data;
      printf("Select the data: ");
      scanf("%d", &data);
      Push(data, &head);
    }
    else if (decision == 2) {
      printf("%d\n", Pop(&head));
    }
    else if (decision == 3) {
      printf("%d\n", Peek(&head));
    }
    else if (decision == 4) {
      break;
    }
    else {
      printf("Invalid Number\n");
    }
  }
}


