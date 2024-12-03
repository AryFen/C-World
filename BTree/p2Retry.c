#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int data;
  struct Node* firstChild;
  struct Node* nextSibling;
};

int CompleteTree(char* btString, int index, struct Node* curr, int indicator);
int SumNodes(struct Node* curr);

int main(void) {
  char* btString = "1(2 3)";
  struct Node* root = malloc(sizeof(struct Node));
  struct Node* curr = root;

  root->data = (int) btString[0] - 48;

  CompleteTree(btString, 2, curr, 1);

  int sum = SumNodes(root);
  printf("Sum: %d\n", sum);  
}

int CompleteTree(char* btString, int index, struct Node* curr, int indicator) {
  int oIndex = index - 2;
  if (indicator == 1) {
    curr->firstChild = malloc(sizeof(struct Node));
    curr = curr->firstChild;
    curr->data = (int) btString[index] - 48;
    indicator = 0;
    index += 1;
  }

  travel:

  if (btString[index] != '(' && btString[index] != ')' && btString[index] != ' ' && indicator == 0) {
    curr->nextSibling = malloc(sizeof(struct Node));
    curr = curr->nextSibling;
    curr->data = (int) btString[index] - 48;
    index += 1;
  }
  if (btString[index] == ' ') {
    index += 1;
    goto travel;
  }
  if (index == strlen(btString) - 1) {
    return 0;
  }
  if (btString[index] == '(') {
    struct Node* temp = curr;
    index += CompleteTree(btString, index + 1, temp, 1);
  }
  if (btString[index] == ')') {
    return index - oIndex;
  }
  if (btString[index] != '(' && btString[index] != ')' && btString[index] != ' ' && indicator == 0) {
    curr->nextSibling = malloc(sizeof(struct Node));
    curr = curr->nextSibling;
    curr->data = (int) btString[index] - 48;
    index += 1;
  }
  if (btString[index] == '(') {
    struct Node* temp = curr;
    index += CompleteTree(btString, index + 1, temp, 1);
  }
  if (btString[index] == ' ') {
    index += 1;
    goto travel;
  }
}

int SumNodes(struct Node* curr) {
  int sum = curr->data;
  if (curr->firstChild != NULL) {
    sum += SumNodes(curr->firstChild);
  }
  if (curr->nextSibling != NULL) {
    sum += SumNodes(curr->nextSibling);
  }
  return sum;
}