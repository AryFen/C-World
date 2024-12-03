#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char data;
  struct Node* firstChild;
  struct Node* nextSibling;
};

int main(void) {
  char* btString = "1(2(3 4 5)6 7 8)";
  struct Node* root = malloc(sizeof(struct Node));
  struct Node* prev = NULL;
  struct Node* curr = root;
  int indicator = 0;

  root->data = btString[0];
  
  for (int i = 1; i < strlen(btString); i++) {
    if (btString[i] == '(') {
      indicator = 1;  
      continue;
    }
    if (btString[i] == ')') {
      curr = prev;
    }
    if (btString[i] == ' ') {
      continue;
    }
    if (btString[i] != '(' && btString[i] != ')' && btString[i] != ' ') {
      if (indicator == 1) {
        curr->firstChild = malloc(sizeof(struct Node));
        prev = curr;
        curr = curr->firstChild;
        curr->data = btString[i];
        indicator = 0;
      }
      else {
        curr->nextSibling = malloc(sizeof(struct Node));
        curr = curr->nextSibling;
        curr->data = btString[i];
      }
    }
  }
}


