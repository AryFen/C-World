#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
  float data;
  struct Node* next;
};

struct Node* PerformOperation(char oper, struct Node* root, int flag);
struct Node* NewNode(struct Node** node, float data);
float Power(int base, int power);
float Pop(struct Node** root);
int IsOperator(char oper);

int main(void) {

  struct Node* root = NULL;
  char* postfixString = "123 4 + 2 * 3 /";
  int passes = 0;
  
  for (int i = 0; i < strlen(postfixString); i++) {
    if (passes - 1 > 0) {
      passes--;
      continue;
    }

    passes = 0;

    if (postfixString[i] == ' ') {
      continue;
    }
    if (IsOperator(postfixString[i]) == 1) {
      char number[100] = "";
      int j = 0;
      while (1) {
        if (postfixString[i + j] != ' ') {
          char temp[2];
          temp[0] = postfixString[i + j];
          temp[1] = '\0';
          strcat(number, temp);
          j++;
          passes++;
        }
        else {
          break;
        }
      }
      NewNode(&root, (float) atoi(number));
    }
    else {
      if (i == strlen(postfixString) - 1)
        root = PerformOperation(postfixString[i], root, 1);
      else {
        root = PerformOperation(postfixString[i], root, 0);
      }
    }
  }
}

int IsOperator(char oper) {

  if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^')  {
    return 0;
  }
  else {
    return 1;
  }
}

struct Node* PerformOperation(char oper, struct Node* root, int flag) {

  if (oper == '+') {
    float operandOne = Pop(&root);
    float operandTwo = Pop(&root);
    struct Node* temp = NewNode(&root, operandOne + operandTwo);
    if (flag == 1) {
      printf("Answer: %f\n", temp->data);
      exit(0);
    }
    return temp;
  }
  else if (oper == '-') {
    float operandTwo = Pop(&root);
    float operandOne = Pop(&root);
    struct Node* temp = NewNode(&root, operandOne - operandTwo);
    if (flag == 1) {
      printf("Answer: %f\n", temp->data);
      exit(0);
    }
    return temp;
  }
  else if (oper == '*') {
    float operandOne = Pop(&root);
    float operandTwo = Pop(&root);
    struct Node* temp = NewNode(&root, operandOne * operandTwo);
    if (flag == 1) {
      printf("Answer: %f\n", temp->data);
      exit(0);
    }
    return temp;
  }
  else if (oper == '/') {
    float denom = Pop(&root);
    float numer = Pop(&root);
    struct Node* temp = NewNode(&root, numer / denom);
    if (flag == 1) {
      printf("Answer: %f\n", temp->data);
      exit(0);
    }
    return temp;
  }
  else if (oper == '^') {
    int power = Pop(&root);
    int base = Pop(&root);
    struct Node* temp = NewNode(&root, Power(base, power));
    if (flag == 1) {
      printf("Answer: %f\n", temp->data);
      exit(0);
    }
    return temp;
  }
}

struct Node* NewNode(struct Node** root, float data) {

  if ((*root) == NULL) {
    (*root) = (struct Node*)malloc(sizeof(struct Node));
    (*root)->data = data;
    (*root)->next = NULL;
    return (*root);
  }
  else {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    struct Node* temp = (*root);
    (*root) = node;
    node->next = temp;
  }
}

float Pop(struct Node** root) {

  if ((*root) != NULL) {
    struct Node* temp = (*root);
    float retVal = temp->data;
    (*root) = (*root)->next;
    free(temp);
    return retVal;
  }
  else {
    printf("Value Error: Invalid Postfix String\n");
    exit(1);
  }
}

float Power(int base, int power) {

  float answer = 1.0;
  for (int i = 0; i < power; i++) {
    answer *= base;
  }
  return answer;
}