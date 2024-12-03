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
  curr->left = NULL;
  curr->right = NULL;
  return curr;
}

struct Node* POSuccessor(struct Node* node);

int main(void) {
  struct Node* root = NewNode(1);
  root->left = NewNode(2);
  root->right = NewNode(3);
  root->left->left = NewNode(4);
  root->left->right = NewNode(5);
  root->left->right->right = root->right;
  root->left->left->right = root->left->right;
  root->right->left = NewNode(6);
  root->right->right = NewNode(7);
  root->right->left->right = root->right->right;

  printf("Data: %d\n", POSuccessor(root)->data);
}

struct Node* POSuccessor(struct Node* node) {
  if (node->left != NULL) {
    return node->left;
  }
  else {
    return node->right;
  }
}