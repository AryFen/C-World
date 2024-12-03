#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* NewNode(int data) {
  struct Node* curr = malloc(sizeof(struct Node));
  curr->data = data;
  curr->right = NULL;
  curr->left = NULL;
  return curr;
}

void printTree(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printf("Data: %d\n", root->data);
  printTree(root->left);
  printTree(root->right);
}

int main(void) {
  struct Node* root = NewNode(1);
  root->left = NewNode(2);
  root->right = NewNode(3);
  root->left->left = NewNode(4);
  root->left->right = NewNode(5);
  root->left->left->left = NewNode(6);
  root->left->left->right = NewNode(7);

  printTree(root);
}