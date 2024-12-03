#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* NewNode(int data) {
  struct Node* curr = malloc(sizeof(data));
  curr->data = data;
  curr->right = NULL;
  curr->left = NULL;
  return curr;
}

int main(void) {

  struct Node* nodeArr[100];

  struct Node* root = NewNode(1);
  root->left = NewNode(2);
  root->left->left = NewNode(4);
  /*
  root->left->right = NewNode(5);
  root->right = NewNode(3);
  root->right->left = NewNode(6);
  root->right->right = NewNode(7);
  */

  struct Node* curr = root;
  int index = 0;

  printf("Data: %d\n", curr->data);

  while (1) {
    while (1) {
      if (curr->left != NULL) {
        nodeArr[index] = curr;
        index++;
        curr = curr->left;
        printf("Data: %d\n", curr->data);
      }
      else {
        break;
      }
    }

    travel:

    index--;
    if (index <= -1) {
      break;
    }
    curr = nodeArr[index];
    if (curr->right != NULL) {
      curr = curr->right;
      printf("Data: %d\n", curr->data);
    }
    else {
      goto travel;
    }
  }
}



