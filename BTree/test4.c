#include <stdio.h>
#include <stdlib.h>

#define K 3

struct Node {
  int data;
  struct Node* left;
  struct Node* middle;
  struct Node* right;
};


void printTree(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printf("Data: %d\n", root->data);
  printTree(root->left);
  printTree(root->middle);
  printTree(root->right);
}

struct Node* NewNode(int data) {
  struct Node* curr = malloc(sizeof(struct Node));
  curr->data = data;
  curr->middle = NULL;
  curr->right = NULL;
  curr->left = NULL;
  return curr;
}

int main(void) {
  struct Node* root = NewNode(1);
  root->left = NewNode(2);
  root->middle = NewNode(3);
  root->right = NewNode(4);
  root->left->left = NewNode(5);
  root->left->middle = NewNode(6);
  root->left->right = NewNode(7);
  root->middle->left = NewNode(8);
  root->middle->middle = NewNode(9);
  root->middle->right = NewNode(10);

  printTree(root);
}
