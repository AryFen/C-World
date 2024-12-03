// Infix to Postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void infixToPostfix(char * infix);
int precedence (char op);
int isOperator(char character);



struct Node {
  char data;
  struct Node *next;
};

int containsBracket(struct Node *head);

void Push(char data, struct Node **head) {
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
    // temp->next = NULL;   
  }
}

char Pop(struct Node **head) {
  if ((*head) != NULL) {
    struct Node *temp = (*head);
    char data = temp->data;
    (*head) = temp->next;
    free(temp);
    return data;
  }
  else {
    printf("Stack Does Not Exist!\n");
    return -1;
  }
}
void Discard(struct Node **head) {
  if ((*head) != NULL) {
    struct Node *temp = (*head);
    char data = temp->data;
    (*head) = temp->next;
    free(temp);
  }
  else {
    printf("Stack Does Not Exist!\n");
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

  FILE *file;
  char str[10];

  file = fopen("expressions.txt", "r");

  if(file == NULL) {
    perror("Error opening file");
    return(-1);
  }
  if (fgets(str, 10, file) !=NULL ) {
    puts(str);
  }
  fclose(file);

  for (int i = 0; i < strlen(str); i++) {
    printf("%c", str[i]);
  }

  printf("%lu", strlen(str));

  infixToPostfix(str);
}

void infixToPostfix(char *infix) {

  struct Node *head = NULL;
  head->next = NULL;

  for (int i = 0; i < strlen(infix); i++) {

    int ASCII = (int) infix[i];

    if ((ASCII >= 65 && ASCII <= 90) || (ASCII >= 97 && ASCII <= 122)) {
      printf("%c", infix[i]);
    }
    else {
      struct Node *temp = head;
      while ((isOperator(temp->data) != 1 && temp->next != NULL)) {
        temp = temp->next;
      }
      if (infix[i] == '(') {
        Push(infix[i], &head);
      }
      if (infix[i] == ')') {
        struct Node * temp4 = head;
        while (temp4->data != '(' || temp4->next != NULL) {
          struct Node *temp5 = temp4;
          temp4 = temp4->next;
          Pop(&temp5);
        }
        Discard(&temp4);
        continue;
      }
      if ((precedence(infix[i]) > precedence(temp->data)) || (head = NULL) || (containsBracket(head))) {
        Push(infix[i], &head);
      }
      else {
        struct Node *temp2 = head;
        int index = -1;

        while (temp2->next != NULL) {
          index++;
          if (temp2->data == '(') {
            break;
          }
          if (precedence(temp2->data) >= precedence(infix[i])) {
            struct Node *temp3 = head;
            for (int i = 0; i < index; i++) {
              temp3 = temp3->next;
            }
            Discard(&temp3);
            index--;
          }
        }
        Push(infix[i], &head);
      }
    }
  }
  struct Node *temp6 = head;
  while (temp6->next != NULL) {
    struct Node *temp7 = temp6;
    temp6 = temp6->next;
    Pop(&temp7);
  }
}

int containsBracket(struct Node *head) {

  struct Node * temp = head;
  while (temp != NULL) {
    if (temp->data == '(') {
      return 1;
    }
    else {
      temp = temp->next;
    }
  }
  return 0;
}


int isOperator(char character) {
  if (character == '^' || character == '*' || character == '/' || character == '+' || character == '-') {
    return 1;
  }
  else {
    return 0;
  }
}

int precedence (char op) {
  if (op == '^') {
    return 3;
  }
  else if (op == '*' || op == '/') {
    return 2;
  }
  else if (op == '+' || op == '-') {
    return 1;
  }
  else {
    return 0;
  }
}
