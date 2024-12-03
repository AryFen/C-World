#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

void AddChild(struct Node* node, int direction, int data);

void printTree(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printTree(root->left);
  printf("Data: %d\n", root->data);
  printTree(root->right);
}

struct Node* NewNode(int data) {
  struct Node* curr = malloc(sizeof(struct Node));
  curr->data = data;
  curr->right = NULL;
  curr->left = NULL;
  return curr;
}

int main(void) {
  struct Node* root = NewNode(1);
  root->left = NewNode(5);
  root->left->left = NewNode(2);
  root->right = NewNode(11);
  root->right->left = NewNode(16);
  root->right->right = NewNode(31);

  printTree(root);
  AddChild(root->right, 1, 18);
  printTree(root);
}

void AddChild(struct Node* node, int direction, int data) {
  if (direction == 1) { // right
    if (node->right == NULL) {
      node->right = NewNode(data);
    }
    else {
      struct Node* temp = node->right;
      node->right = NewNode(data);
      node->right->right = temp;
    }
  }
  else { // left
    if (node->left == NULL) {
      node->left = NewNode(data);
    }
    else {
      struct Node* temp = node->left;
      node->left = NewNode(data);
      node->left->left = temp;
    }
  }
}